#ifndef CAR_H
#define CAR_H

class Car : public Vehicle
{
private:
	char *color;
	int numberof_seats;
	char *model;
	static num
public:
	Car();
	Car(char *, int , char* );
	Car &operator = (const Car &rhs);
	Car(const Car &);
	void readcardata();
	void printcardata();
	~Car();
	
};
#endif