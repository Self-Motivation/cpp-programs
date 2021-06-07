//prgram using class and implementation of assignment and copy constructor
//implementation of default and programmer defined constructor and destructor
//implementation of namespace and access specifier
//first program of third assignment
#include <iostream>
#include <cstring>

using namespace std;

namespace space1{
	class Student
	{
	private: //access specifier
		char *name;
		int age;
		int year;
		char *department;
		
	public:	//access specifier
		static int studentcount;
		Student(); //default constructor
		Student(char *sn, int sa, int sy, char *sd); //overloaded constructor
		Student(const Student &rhs); //copy constructor
		Student & operator=(const Student &rhs); //assignment operator
		
		
		void Readstudentdata();
		void printstudentdata() const;
		~Student();	//destructor

	};

	Student::Student():name(NULL), age(0), year(1), department(NULL)
	{
		studentcount++;
	}

	Student::Student(char *sn, int sa, int sy, char *sd):age(sa), year(sy)
	{
		studentcount++;
		name = new char[strlen(sn)+1];
		strcpy(name, sn);
		department = new char[strlen(sd)+1];
		strcpy(department, sd);
	}

	Student::Student(const Student &rhs): age(rhs.age), year(rhs.year)
	{
		name = new char[strlen(rhs.name)+1];
		department = new char[strlen(rhs.department)+1];
		strcpy(name, rhs.name);
		strcpy(department, rhs.department);
	}

	Student & Student::operator = (const Student &rhs)
	{
		if(this == &rhs) return *this;

		name = new char[strlen(rhs.name)+1];
		department = new char[strlen(rhs.department)+1];
		strcpy(name, rhs.name);
		strcpy(department, rhs.department);
		return *this;
	}

	Student::~Student(){
		delete[] name;
		delete[] department;
		age = 0;
		year = 1;
	}

	void Student::Readstudentdata()
	{
		name = new char[20];
		department = new char[30];
		cout << "Enter name, age, year and department of Student respectively: "<< endl;
		cin >> name >> age >> year >> department;
	}
	void Student::printstudentdata() const
	{
		cout << "Student name: "<< this->name << endl;
		cout << "Student age: "<<this->age << endl;
		cout << "year: "<<this->year << endl;
		cout << "department: "<<this->department << endl;
	}
}
using namespace space1;
int Student::studentcount = 0;
int main()
{
	Student s1;
	s1.Readstudentdata();
	s1.printstudentdata();

	char sn[20];
	char sd[30];
	int sa, sy;
	cout << "Enter another student data: ";
	cin >> sn >> sa >> sy >> sd;
	Student s2(sn, sa, sy, sd);

	Student s3(s1);
	cout << "Copy constructor called" << endl;
	s3.printstudentdata();

	Student s4;
	s4 = s2;
	cout << "assignment operator called: " << endl;
	s4.printstudentdata();
}