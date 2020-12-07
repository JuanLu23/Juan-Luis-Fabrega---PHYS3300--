#include "WAMWorld.h"

void WAMWorld::SetGravity(const vec2D& g)
{
	// Funcion que establece la gravedad al recivir la iniciacion del main 
	gravity = g;
}

void WAMWorld::addBody(WBody* b)
{
	// funcion que guarda los cuerpos dentro del vector bidies al nuevo cuerpo ser creado
	bodies.push_back(b);
}

void WAMWorld::Step(float dt)
{
	// Funcion que le da velocidad a un cuerpo y esta lo mueve con esa creada velocidad que aumenta poco a poco 
	// for que aumenta la velocidad 
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]-> force.x * bodies[counter]-> inMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->inMass) * dt;
	}

	// for que mueve el cuerpo con la velocidad 
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x = bodies[counter]->velocity.x * dt + bodies[counter]->position.x;
		bodies[counter]->position.y = bodies[counter]->velocity.y * dt + bodies[counter]->position.y;

		bodies[counter]->force.setZero();
	}
}
