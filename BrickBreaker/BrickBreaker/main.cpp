#include <raylib.h>
#include <raymath.h>

#include "DuckTools.h"
#include <vector>

#define WINDOW_SIZE_X 1000
#define WINDOW_SIZE_Y 1000



int main()
{
	InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Chaos!");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);



		EndDrawing();
	}

	return 0;
}
