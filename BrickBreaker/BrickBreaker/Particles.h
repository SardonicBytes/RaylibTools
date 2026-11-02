#pragma once
#include <vector>
#include <raylib.h>

#define POOL_SIZE 1000


struct Particle
{
	Vector2 position;
	Vector2 velocity;
	bool enabled = false;
	float timeCreated;
	float particleSize;
	Color particleColor;
};


class ParticleSystem
{
public:

	std::vector<Particle> particles;
	
	
	//Particle Settings
	float gravity = 30;
	float maxLife = 1.0f;
	float initialParticleSize = 10;
	Color initialParticleColor = RED;


	void Start();
	void Emit(Vector2 emissionSource);
	void Update();
	void Render() const;
};