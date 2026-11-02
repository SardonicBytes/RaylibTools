# BrickBreaker

A work-in-progress brick breaker built with C++ and [raylib](https://www.raylib.com/). There are no bricks yet. So far the project has a particle system and a reusable button class.

![Colourful particles trailing behind the mouse cursor](ParticleSystem.gif)

## Controls

Hold the left mouse button to emit particles from the cursor. Press Esc to quit.

## Particle system

Each particle gets a random direction, speed, size and colour when it spawns. It then falls, grows slightly and fades out over its lifetime. Particles are drawn with additive blending, so overlapping ones get brighter.

Particles come from a fixed pool that is allocated once at startup. Emitting reuses disabled particles, so nothing is allocated while the game runs. If the pool runs out, nothing more spawns until a particle expires.

You can adjust these settings in [`Particles.h`](BrickBreaker/BrickBreaker/Particles.h):

| Setting | Default | What it does |
| --- | --- | --- |
| `POOL_SIZE` | `1000` | Maximum number of particles alive at once |
| `gravity` | `30` | Downward movement, in pixels per second |
| `maxLife` | `1.0` | How long each particle lives, in seconds |

The spawn ranges for speed, size, colour and particles per frame are set in `ParticleSystem::Emit` in [`Particles.cpp`](BrickBreaker/BrickBreaker/Particles.cpp).

## Building

You need Visual Studio with the **Desktop development with C++** workload and the v143 build tools. raylib 6.2.0 comes from NuGet.

1. Open `BrickBreaker/BrickBreaker.sln`.
2. Restore the NuGet packages if Visual Studio doesn't do it automatically.
3. Select the `x64` platform, then build and run.

## Project layout

| File | Purpose |
| --- | --- |
| `main.cpp` | Window setup and the main loop |
| `Particles.h`, `Particles.cpp` | `Particle` struct and `ParticleSystem` class |
| `Button.h`, `Button.cpp` | `Button` class with hover and click states (not used by the game yet) |
| `DuckTools.h` | Helpers for polar coordinates and random directions |
