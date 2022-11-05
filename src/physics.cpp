#include <math.h>
#include "physics.hpp"
#include "raylib.h"
#include "raymath.h"

namespace Physics {
	// using 1 as the const
	//const float gravitational_constant = 6.67;//e-11;
	//grav = grav_const × (r_mass / distance^2)
	//force = s_mass * grav
	//force = s_mass * (grav_const * (r_mass / distance^2))

	Body::Body(Vector2 position, Vector2 velocity, float mass):position(position), velocity(velocity), mass(mass) {
	}

	Body ship = Body((Vector2){200,400}, (Vector2){0,0.5}, 1);
	Body rock = Body((Vector2){400,400}, (Vector2){0,0}, 50);

	//0.01667
	void step(float deltaTime) {
		// calculate velocity change
		//pow((rock.position.x - ship.position.x),2) + pow((rock.position.y - ship.position.y),2);
		float distance = Vector2DistanceSqr(ship.position, rock.position);
		Vector2 force = Vector2Normalize(Vector2Subtract(rock.position, ship.position));
		ship.velocity = Vector2Add(ship.velocity, Vector2Scale(force, ship.mass * (rock.mass / (distance/*this is pre squared*/)) * deltaTime));
		// calculate position change
		ship.position = Vector2Add(ship.position, Vector2Scale(ship.velocity, deltaTime));
	}

}
