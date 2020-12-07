#ifndef WAMBODY_H
#define WAMBODY_H

#include "WAMVectorCalculation.h"

struct WBody {

	// Constructor de la libreria WBody
	WBody();

	// Variables que utiliza el cuerpo 
	float mass;
	float inMass;

	// Vectores o varibales que utiliza el cuerpo para su movimiento 
	vec2D position;

	vec2D velocity;

	vec2D force;

	// Funcion que le agrega la fuerza de movimiento al cuerpo de vec2D 
	void addForce(const vec2D& f);

	// Funtion that will set the mass for the body
	void SetMass(const float &m);

	// Funtion that displays information  
	void DisplayBodyInfo();
};

#endif 
