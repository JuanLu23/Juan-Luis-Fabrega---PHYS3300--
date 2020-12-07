#include "WAMBody.h"

WBody::WBody()
{
	// The constructior initializes all the varibles with the function .setZero() which will give the variables 
	//  the value of 0f
	position.setZero();

	velocity.setZero();

	force.setZero();

	// other variables that the body needs 
	mass = 1.0f;
	inMass = 1.0f; 
}

void WBody::addForce(const vec2D& f) 
{
	// Function that increases the force by adding the force plus the variable that the function recieves 
	force += f;
}

void WBody::SetMass(const float& m)
{
	// Function that stablishes the masses 
	mass = m;
	inMass = 1 / m;
}

void WBody::DisplayBodyInfo()
{
	// function that displays all the variables of the function 
	std::cout << "mass: " << mass << std::endl;
	std::cout << "InvMass: " << inMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;

}
