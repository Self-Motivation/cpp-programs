#include <iostream>
#include <vehicle.hpp>

Car::Car(int prc, char* manu, char *clr, int a, char* mdl ):numberof_seats(a)
{
	Vehicle(prc, manu);
	color = new char[20];
	strcpy(color, clr);
	model = new char[20];
	strcpy(model, mdl);
}
Car::Car(const Car &rhs)
{
	Vehicle(rhs.prc, rhs.manu);
	color = new char[20];
	strcpy(color, clr);
	model = new char[20];
	strcpy(model, mdl);
}


