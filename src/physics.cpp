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

    std::unordered_set<DynamicBody*>DynamicBody::dynamicBodies;
    std::unordered_set<KinematicBody*>KinematicBody::kinematicBodies;

	Body::Body(Vector2 position, Vector2 velocity, float mass):position(position), velocity(velocity), mass(mass) {
	}

	DynamicBody::DynamicBody(Vector2 position, Vector2 velocity, float mass):Body(position, velocity, mass) {
        dynamicBodies.insert(this);
	}

    DynamicBody::~DynamicBody() {
        dynamicBodies.erase(this);
    }

	KinematicBody::KinematicBody(Vector2 position, Vector2 velocity, float mass):Body(position, velocity, mass) {
        kinematicBodies.insert(this);
	}

    KinematicBody::~KinematicBody() {
        kinematicBodies.erase(this);
    }

	Body ship = Body((Vector2){200,400}, (Vector2){0,0.5}, 1);
	Body rock = Body((Vector2){400,400}, (Vector2){0,0}, 50);

	//0.01667
	void step(float deltaTime, int times) {
        for (int i = 0; i < times; i++) {
            // calculate position change
            Vector2 grav_force = get_grav_force(ship, rock);
            ship.velocity = Vector2Add(ship.velocity, Vector2Scale(grav_force, deltaTime));
            ship.position = Vector2Add(ship.position, Vector2Scale(ship.velocity, deltaTime));
        }
	}

    Vector2 get_grav_force(Body body1, Body body2) {
		float distance_sqr = Vector2DistanceSqr(body1.position, body2.position);
		Vector2 direction = Vector2Normalize(Vector2Subtract(body2.position, body1.position));
        return Vector2Scale(direction, body1.mass * (body2.mass / (distance_sqr)));
    }
}
