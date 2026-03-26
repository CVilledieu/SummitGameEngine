Recommended approach

Keep the same architecture split from the base note, but map it onto your current tree incrementally instead of renaming everything at once. The goal is to make your current `director`, `scene`, `mesh`, and `render` code converge toward a cleaner frame pipeline without a large rewrite.

Recommended primary systems in this codebase

1. Core
- Responsibility: engine startup/shutdown, frame boundaries, timing, diagnostics, allocators later if you add them.
- Current home:
  - `src/engine/root/`
  - `src/engine/common/`
- Keep here:
  - top-level engine orchestration
  - engine config/types
  - assertions/logging/timing utilities as they appear

2. Platform
- Responsibility: window creation, input polling, filesystem/platform-specific services.
- Current home:
  - `src/engine/render/wnd.h`
  - `src/engine/util/fs/`
- Longer term:
  - consider a dedicated `src/engine/platform/` folder once window/input code grows beyond a couple files

3. Assets
- Responsibility: stable asset IDs, load requests, source paths, metadata for textures/shaders/meshes.
- Current state:
  - partially implied by shader files and filesystem helpers
- Recommended new home:
  - `src/engine/assets/`
- First scope:
  - texture asset descriptors
  - shader asset descriptors
  - path resolution helpers
- Important rule:
  - assets should describe resources, not hold per-entity scene state

4. World
- Responsibility: authoritative runtime game state.
- Current likely home:
  - `src/engine/director/scene/`
- Recommended shape:
  - scene becomes world state plus query helpers
  - contains transforms, sprite references, layer/order, visibility flags, maybe cameras later
- Avoid:
  - GPU buffer packing
  - shader binding decisions
  - GL-facing structs

5. Runtime registries
- Responsibility: map stable IDs to runtime handles/cached records.
- Current likely home:
  - `src/engine/mesh/registry.c`
- Recommended direction:
  - broaden the idea of registry beyond mesh data
  - either keep registries under `src/engine/mesh/` temporarily and later move to `src/engine/registry/`, or create `src/engine/registry/` once there are 2-3 registry types
- Good first registries:
  - texture registry: asset ID -> GPU texture handle
  - shader registry: asset ID -> compiled shader/program handle
  - sprite/mesh template registry: asset ID -> static geometry description or buffer region

6. Render submission
- Responsibility: read world state and registries, emit transient draw commands for one frame.
- Recommended new home:
  - `src/engine/render/submit.c`
  - `src/engine/render/submit.h`
- This is the missing middle layer in your current architecture.
- Input:
  - read-only scene/world view
  - runtime registries
  - camera/frame parameters
- Output:
  - a transient command stream or packed instance stream that your renderer already knows how to consume

7. Render backend
- Responsibility: own GPU resources, ring buffer, GL upload, draw submission, present.
- Current home:
  - `src/engine/render/`
  - `src/engine/render/graphics/`
  - `src/engine/render/shaders/`
- Keep renderer focused on:
  - buffer lifecycle
  - shader/program use
  - state binding
  - draw execution
- Avoid putting scene traversal logic here.

How your current systems should relate

Use this flow:

```text
game -> director/scene(world state)
scene(world state) -> render_submit
render_submit -> render backend
render backend -> GPU
```

That means:
- game code asks to create or mutate entities/world data
- world/scene stores the authoritative state
- render submission extracts only render-relevant data for this frame
- renderer executes prebuilt commands and does not inspect gameplay state directly

What `scene` should own vs not own

Scene/world should own:
- entity/object lifetime
- transforms
- sprite/material references by stable ID
- draw layer / sorting category input
- visibility flags
- camera attachment references if needed

Scene/world should not own:
- GPU handles
- GL object IDs
- mapped ring-buffer pointers
- final packed vertex payloads for the renderer
- shader binding logic

This is the main change that keeps scene from becoming oversized while still keeping it central.

What `render_submit` should do

This module should be very explicit and boring. For each visible renderable in the world it should:

1. Read the world-facing render component or equivalent scene record.
2. Resolve asset IDs through registries.
3. Generate a sort key.
4. Write a compact transient command.
5. Hand the command stream to the renderer.

Example transient command shape:

```c
typedef struct RenderCommand_t {
    uint32_t sort_key;
    uint32_t texture_handle_index;
    uint32_t shader_handle_index;
    float transform[6];
    float uv_rect[4];
    float color[4];
} RenderCommand_t;
```

The exact fields can change, but the point is that this is frame-local data, not authoritative game state.

What to do with `mesh/registry.c`

Right now, treat it as the seed of a broader runtime registry concept.

Practical options:

1. Keep it where it is for now
- good if it currently only manages render geometry-related records
- add a comment or note that this is a runtime registry, not scene state

2. Split by domain as usage grows
- `render/texture_registry.*`
- `render/shader_registry.*`
- `mesh/mesh_registry.*`

3. Centralize later
- if you end up with several registries sharing common patterns, create `src/engine/registry/`

For a solo portfolio engine, option 1 or 2 is the right starting point. Do not centralize too early unless you can already see repeated behavior.

Suggested folder direction with minimal disruption

```text
src/engine/
  root/
  common/
  director/
    director.c
    scene/
      scene.c            # world state and scene queries
  assets/                # new when needed
  render/
    render.c             # backend entry point
    submit.c             # new: frame submission
    graphics/
    shaders/
  mesh/
    registry.c           # keep for now if mesh-specific
  util/
  platform/              # optional later
```

Recommended API boundaries

Keep the interfaces narrow and one-directional:

- `scene.h`
  - create/destroy scene
  - create entities/renderables
  - mutate transforms/render references
  - query read-only views for submission

- `submit.h`
  - begin frame submission
  - submit scene/world to command stream
  - finalize command stream

- `render.h`
  - initialize renderer
  - execute prepared frame
  - shutdown renderer

- registry headers
  - resolve stable IDs to runtime handles
  - create/destroy registry contents
  - debug validation helpers if useful

If one layer starts needing a lot of another layer's private structs, the boundary is probably wrong.

Incremental adoption plan for this repository

1. First add `render_submit`
- Make it output exactly what `render.c` already wants.
- Do not redesign the renderer yet.

2. Shrink scene responsibilities
- Move any render packing/sorting code out of scene into submit.
- Keep scene authoritative.

3. Introduce texture registry first
- This is usually the highest-value registry in a small 2D engine.
- Stable texture IDs will make submission and renderer boundaries much cleaner.

4. Add debug inspection points
- command count per frame
- visible object count
- batch count / draw count
- registry hit/miss or load state

These diagnostics are disproportionately useful in a portfolio engine because they make the architecture legible.

Short rule of thumb

- Assets answer: what resource is this?
- World answers: what exists right now?
- Registries answer: what runtime handle/cache entry represents it?
- Submission answers: what do we draw this frame?
- Renderer answers: how does it get to the GPU?

If you keep those five questions separated, your engine structure will stay healthy.