# RaylibTools

A small collection of reusable tools for C++ and [raylib](https://www.raylib.com/). It currently has a particle system and a button class, and more tools may be added later.

![Colourful particles trailing behind the mouse cursor](ParticleSystem.gif)

## Particle system

`ParticleSystem` emits particles from the mouse cursor while the left mouse button is held down. Each particle gets a random direction, speed, size and colour when it spawns. It then falls, grows slightly and fades out over its lifetime.

Particles come from a fixed pool that is allocated once by `Start()`. Emitting reuses disabled particles, so nothing is allocated after that. If the pool runs out, nothing more spawns until a particle expires.

```cpp
#include "Particles.h"

ParticleSystem particles;

// Once, after InitWindow
particles.Start();

// Every frame, between BeginDrawing and EndDrawing
particles.Update();
particles.Render();
```

The GIF above uses additive blending, so overlapping particles get brighter. To get the same look, put `Update()` and `Render()` between `BeginBlendMode(BLEND_ADDITIVE)` and `EndBlendMode()`.

You can adjust these settings in `Particles.h`:

| Setting | Default | What it does |
| --- | --- | --- |
| `POOL_SIZE` | `1000` | Maximum number of particles alive at once |
| `gravity` | `30` | Downward movement, in pixels per second |
| `maxLife` | `1.0` | How long each particle lives, in seconds |

The spawn ranges for speed, size, colour and particles per frame are set in `ParticleSystem::Emit` in `Particles.cpp`.

## Button

`Button` is a clickable rectangle with a text label. It changes colour when hovered and flashes when clicked. You can change its position, text and colours through its public fields, and `pressAction` is an optional function to run on each click.

```cpp
#include "Button.h"

Button button;
button.message = "Play";
button.pressAction = []() { TraceLog(LOG_INFO, "Clicked"); };

// Every frame, between BeginDrawing and EndDrawing
button.Update();
button.Render();
```

Each click also prints `Button Pressed` to the console.

## Running the demo

`main.cpp` runs the particle system demo. Hold the left mouse button to emit particles, and press Esc to quit. The button class is included in the project, but the demo doesn't use it.

You need Visual Studio with the **Desktop development with C++** workload and the v143 build tools. raylib 6.2.0 comes from NuGet.

1. Open the `.sln` file in Visual Studio.
2. Restore the NuGet packages if Visual Studio doesn't do it automatically.
3. Select the `x64` platform, then build and run.

## Project layout

| File | Purpose |
| --- | --- |
| `main.cpp` | Particle system demo |
| `Particles.h`, `Particles.cpp` | `Particle` struct and `ParticleSystem` class |
| `Button.h`, `Button.cpp` | `Button` class |
| `DuckTools.h` | Helpers for polar coordinates and random directions |
