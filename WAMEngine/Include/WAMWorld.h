#ifndef WAMWORLD_H
#define WAMWORLD_H

#include "WAMVectorCalculation.h"
#include "WAMBody.h"
#include <vector>

	struct WAMWorld
	{
		// Generando el constructor e inicialuzandolo 
		WAMWorld() {}
		WAMWorld(vec2D gravity) : gravity(gravity) {}

		// Creando el vector o variable de gravedad 
		vec2D gravity;

		// Se crea el vector de objetos donde se guardaran los objetos creados dentro del mundo 
		std::vector<WBody*> bodies;

		// Funcion que le da valor a la gravedad
		//	en el momento que el mundo (cosntructor) es creado este se le da dos valores
		//  como en el main se inicializa el mundo este se le envia dos valores uno de estos es la gravedad
		void SetGravity(const vec2D &g);

		// Funcion que genera un cuerpo y lo guarda en el vector 
		void addBody(WBody* b);

		// Funcion que calcula la matematica de mundo o el caminar del bodies creado 
		void Step(float dt);

	};


#endif 

