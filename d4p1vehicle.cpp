#include <iostream>
#include <cstring>
using namespace std;




Vehicle::Vehicle():price(0), manufacturer(NULL)
{

}

Vehicle::Vehicle(int a, char* &b): price(a)
{
	manufacturer = new char[20];
	strcpy(manufacturer, b);
}
Vehicle::Vehicle(int a)
{
	manufacturer = new char[20];
	cin >> manufacturer;
}
Car::Car():color(NULL),numberof_seats(0),model(NULL)
{
	Vehicle();
}