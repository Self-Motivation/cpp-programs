##ifndef VEHICLE
#define VEHICLE

class Vehicle
{
private:
	int price;
	char *manufacturer;
	static no_of_vehicles;
public:
	Vehicle();
		Vehicle(int , char*);
		Vehicle(int );
		Vehicle(const Vehicle &);
		Vehicle & operator=(const Vehicle &);
		void readvehicledata();
		void printvehicledata();
	~Vehicle();
	
};

#endif