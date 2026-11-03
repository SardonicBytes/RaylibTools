#pragma once

#include "raylib.h"
#include "raymath.h"

inline Vector2 PolarToVector(float dist, float angle)
{
	return Vector2
	{
		dist * (float)cos(DEG2RAD * angle),
		dist * (float)sin(DEG2RAD * angle)
	};
}

inline Vector2 GetRandomDirection ()
{
	float randomDirection = GetRandomValue(0, 360);
	return PolarToVector(1,randomDirection);
}


