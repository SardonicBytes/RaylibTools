#include <raylib.h>
#include <raymath.h>

#include "DuckTools.h"
#include <vector>
#include "Particles.h"

#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 800


ParticleSystem particles;


void Initialization()
{
	particles.Start();
}


int main()
{
	InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Chaos!");
	SetTargetFPS(60);

	Initialization();


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		BeginBlendMode(BLEND_ADDITIVE);

		//Particles
		particles.Update();
		particles.Render();

		EndBlendMode();

		EndDrawing();
	}

	return 0;
}
