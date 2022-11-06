#pragma once
#include "raylib.h"

namespace Physics {

	class Body {
		public:
			Vector2 position;
			Vector2 velocity;
			float mass;
			Body(Vector2 position, Vector2 velocity, float mass);
	};

	extern Body ship;// = Body((Vector2){50,50}, (Vector2){0,1}, 1);
	extern Body rock;// = Body((Vector2){400,400}, (Vector2){0,0}, 50);

	//0.01667
	void step(float deltaTime);
    Vector2 get_grav_force(Body body1, Body body2);
}
