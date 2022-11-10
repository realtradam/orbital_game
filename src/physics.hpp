#pragma once
#include <unordered_set>
#include "raylib.h"

namespace Physics {
	class Body {
		public:
			Vector2 position;
			Vector2 velocity;
			float mass;
			Body(Vector2 position, Vector2 velocity, float mass);
	};

    // TODO: replace these hardcoded bodies with dynamic/kinematic bodies in gameplay system
	extern Body ship;// = Body((Vector2){50,50}, (Vector2){0,1}, 1);
	extern Body rock;// = Body((Vector2){400,400}, (Vector2){0,0}, 50);

    class DynamicBody : public Body {
        private:
            static std::unordered_set<DynamicBody*> dynamicBodies;
        public:
            void apply_force(Vector2 force);
            DynamicBody(Vector2 position, Vector2 velocity, float mass);
            ~DynamicBody();
    };

    class KinematicBody : public Body {
        private:
            static std::unordered_set<KinematicBody*> kinematicBodies;
        public:
            KinematicBody(Vector2 position, Vector2 velocity, float mass);
            ~KinematicBody();
    };

	//0.01667
	void step(float deltaTime, int times=1);
    Vector2 get_grav_force(Body body1, Body body2);
}
