# Things to remember

What to build first (highest ROI)

Scene graph/entity list + transform inspector.
Asset browser with stable IDs and reimport.
Play/stop loop using the same runtime codepath.
Immediate diagnostics panel: draw calls, frame time, loaded assets, warnings.
Simple serialization format for scenes (deterministic, diff-friendly).
Why this is the right balance

Performance: minimal overhead and less tooling debt.
Complexity: avoids building a second engine inside the editor.
Portfolio impact: clearly demonstrates subsystem boundaries, data flow, and practical tooling decisions.
Practical next step

Define one vertical slice: create sprite entity in editor, save scene, load in runtime, run, edit, reload.
If that loop is smooth, expand editor features around it instead of adding isolated UI features.