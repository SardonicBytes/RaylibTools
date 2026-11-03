#include "Particles.h"
#include "raymath.h"
#include "DuckTools.h"

void ParticleSystem::Start()
{
	particles.reserve(POOL_SIZE);
	for (int i = 0; i < particles.capacity(); i++)
	{
		particles.push_back(Particle{});
	}
}



void ParticleSystem::Emit(Vector2 emissionSource)
{
	int numberToEmit = GetRandomValue(1,20);
	float timeCreated = (float)GetTime();
	int emitted = 0;

	for (auto& particle : particles)
	{
		if (emitted >= numberToEmit) break;
		if (particle.enabled) continue;

		particle = Particle
		{
			emissionSource,
			GetRandomValue(10,50) * GetRandomDirection(),
			true,
			timeCreated,
			(float)GetRandomValue(3,20),
			Color
			{
				(unsigned char)GetRandomValue(0,255),
				(unsigned char)GetRandomValue(0,255),
				(unsigned char)GetRandomValue(0,255),
				255
			}
		};
		emitted++;
	}
}

void ParticleSystem::Update()
{
	if(IsMouseButtonDown(0))
	{
		Emit(GetMousePosition());
	}

	for(auto& particle : particles)
	{
		if(!particle.enabled) continue;

		float life = ((float)GetTime() - particle.timeCreated) / maxLife;
		if (life >= 1.0f)
		{
			particle.enabled = false;
			continue;
		}

		particle.position += particle.velocity * GetFrameTime();
		particle.position.y += gravity * GetFrameTime();
		particle.particleColor.a = (unsigned char)(255 * (1.0f - life));
		particle.particleSize += 0.6f * GetFrameTime();
	}
}

void ParticleSystem::Render() const
{
	for (auto& particle : particles)
	{
		if(!particle.enabled) continue;
		DrawCircle(particle.position.x,particle.position.y,particle.particleSize,particle.particleColor);
	}
}
