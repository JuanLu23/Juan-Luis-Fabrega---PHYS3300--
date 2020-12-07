#ifndef WAMVECTORCALCULATOR_H
#define WAMVECTORCALCULATOR_H

#include <iostream>
#include <math.h>
#include <float.h>
#include <stdlib.h>

struct vec2D
{
	// Declaramos las componentes del vector. 
	float x, y;

	// Creamos un constructor DEFAULT. 
	vec2D(){}

	// Creamos un constructor para pasar las componentes del vector.
	vec2D(float x, float y) : x(x), y(y) {}

	// Creamos una función para establecer el vector como cero (componentes cero). 
	void setZero();

	// Creamos una función que nos permita cambiar el valor de ambas componentes. 
	void Set(const float& x_, const float& y_);

	// Creamos una función para imprimir las componentes del vector.
	void displayVector() const;

	// Definimos una función que calcule la longitud CUADRADA del vector. 
	float lengthSquared() const;

	// Definimos una función que calcula la longitud del vector. 
	float length() const;

	// Creamos un método para sumarle un vector al vector actual. 
	void operator += (const vec2D& v);

	// Creamos un método para restarle un vector al vector actual. 
	void operator -= (const vec2D& v);

	// Creamos un método para multiplicar el vector por un escalar.
	void operator *= (const float& k);

};

inline vec2D operator + (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x + b.x, a.y + b.y);
}

inline vec2D operator - (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x - b.x, a.y - b.y);
}

inline vec2D operator * (const float& k, const vec2D& v)
{
	return vec2D(k * v.x, k * v.y);
}

#endif /*HALOMATH_H*/
