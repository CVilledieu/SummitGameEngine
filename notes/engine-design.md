Recommended approach

Shape the engine around a small, explicit frame pipeline with 5 core runtime systems, not just "scene + renderer":

1. Asset system (offline-ish/runtime metadata)
2. World/scene state (authoritative game data)
3. Runtime registries (GPU/runtime handles and lookup tables)
4. Frame submission (build transient render commands)
5. Renderer backend (consume commands, issue GPU work)

That split keeps your renderer lean while preventing `scene` from becoming a god module.

What this looks like in practice

1. Asset metadata and scene data
- Asset metadata: what exists on disk and how to load it.
- Scene data: what exists in the current world and where it is.
- Keep these separate.
- Example:
	- Asset: "sprite player_idle, texture atlas X, UV rect Y"
	- Scene: "entity 42 uses sprite player_idle at position (10, 4), layer 3"

Why:
- Asset info changes rarely.
- Scene info changes every frame.
- Different lifetimes and update frequencies.

2. Runtime registries
- Map stable IDs (asset/entity IDs) to runtime objects (GPU handles, cached pointers, packed indices).
- Typical registries in a 2D engine:
	- Texture registry: asset ID -> GPU texture handle
	- Mesh/quad template registry: ID -> vertex/index buffer regions
	- Material/shader registry: ID -> pipeline/program state
	- Entity render registry: entity ID -> render-facing compact record

Why:
- Avoid repeatedly resolving strings/paths during frame build.
- Central place for lifetime/state validation.
- Easy debug introspection for portfolio value.

3. Frame submission (important middle layer)
- Takes world state + registries, emits transient render commands for this frame only.
- Output could be a command buffer/ring-buffer payload like:
	- draw sprite X with transform T, color C, sort key K
- Performs:
	- visibility/culling (simple for 2D, still useful)
	- sort-key generation (layer/material/texture)
	- batching-friendly ordering
- Does not call GL directly.

Why:
- Separates "what to draw" from "how GPU API draws it".
- Lets you test/inspect frame generation independently.
- Keeps renderer backend focused on execution only.

4. Renderer backend
- Owns GPU resources, ring buffer, synchronization, and API calls.
- Consumes prepared frame commands.
- Responsibilities:
	- upload transient data
	- bind pipelines/textures/buffers
	- issue draw calls
	- present

Why:
- Clean boundary and easier future backend swap/refactor.
- Keeps your original renderer philosophy intact.

5. World/scene system split
Your current "scene" should become two smaller parts:
- World state: entities/components, transforms, gameplay-owned data.
- Scene query/view layer: read-only extraction for systems (render submitter, physics, etc.).

Why:
- Gameplay writes world state.
- Submitter reads from world snapshot/view.
- Reduces coupling and accidental renderer-specific data leaking into gameplay.

Minimal primary systems for your portfolio engine

Use this as your "v1 architecture target":

- `core`: frame clock, memory arenas, logging/asserts
- `assets`: manifests, asset IDs, loading metadata
- `world`: entities/components/transforms (authoritative runtime state)
- `registries`: runtime lookup/caches for render resources
- `render_submit`: world -> transient render command stream
- `render_backend`: GPU execution, ring buffer, draw submission
- `platform`: window/input/filesystem
- `game`: game-specific logic on top of world APIs

A simple per-frame flow

$$
	ext{game update} \rightarrow \text{world mutate} \rightarrow \text{render submit build} \rightarrow \text{renderer execute} \rightarrow \text{present}
$$

Or in pseudocode:

```c
engine_begin_frame();

platform_poll_input();
game_update(world, dt);                  // mutate authoritative state

render_submit_begin(submit_ctx);
render_submit_world(submit_ctx, world, registries); // build transient commands
render_submit_end(submit_ctx);

renderer_execute_frame(renderer, submit_ctx->command_stream); // GL calls happen here
engine_end_frame();
```

Tradeoffs (brief)

- Pros:
	- Clear ownership/lifetimes
	- Better performance path (sorting/batching in submit stage)
	- Strong portfolio story: "data flow architecture, not monolith scene"
- Costs:
	- Slightly more boilerplate upfront
	- Need discipline around boundaries

Practical next step (incremental)

Do this in 3 steps without big rewrites:

1. Introduce a `render_submit` module
- Input: read-only world/scene view
- Output: current renderer's expected buffer format
- Keep renderer unchanged initially.

2. Introduce one registry first
- Start with texture registry only.
- Replace ad-hoc texture lookup/loading paths with ID->handle resolution.

3. Narrow `scene` responsibilities
- Move renderer-specific packing/sorting out of scene into `render_submit`.
- Scene stays authoritative world data + query helpers.
