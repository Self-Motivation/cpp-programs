//dynamic implementation of array at runtime using class in cpp
//user can imput max numbers of datas, until then it can be expanded as per need
//program2 of assignment 3

#include <iostream>

using namespace std;

namespace space{
	class Runtimesizearray
	{
	private:
		int *rsa, MAX, rsalen, count;
		
	public:
		static int arraycount;
		Runtimesizearray();
		Runtimesizearray(int max);
		Runtimesizearray(const Runtimesizearray&);
		Runtimesizearray(int *, int, int);

		Runtimesizearray & operator=(const Runtimesizearray &);

		void inflate(Runtimesizearray&, int);
		void readata();
		void addelement();
		int fetchelement(int);
		inline void resetelement(int, int);
		inline int getmaxsize();
		inline int getelementcount();
		~Runtimesizearray();
		
	};
	Runtimesizearray::Runtimesizearray()
	{
		rsa = new int[10];
		rsalen = 10;
		MAX = 100;
		arraycount++;
	}
	Runtimesizearray::Runtimesizearray(int max)
	{
		rsa = new int[10];
		rsalen = 10;
		MAX = max;
		arraycount++;
	}
	Runtimesizearray::Runtimesizearray(int *array, int arraysize, int max = 100)
	{
		arraycount++;
		rsa = new int[arraysize];
		rsalen = arraysize;
		count = 0;
		for (int i = 0; i < arraysize; ++i)
		{
			rsa[i] = array[i];
			count++;
		}
		MAX = max;
	}
	Runtimesizearray::Runtimesizearray(const Runtimesizearray &rhs)
	{
		count = 0;
		rsa = new int[rhs.rsalen];
		for (int i = 0; i < rhs.count; ++i)
		{
			this->rsa[i] = rhs.rsa[i];
			count++;
		}
		arraycount++;
	}

	Runtimesizearray & Runtimesizearray::operator = (const Runtimesizearray &rhs)
	{
		arraycount++;
		count = 0;
		if(*this->rsa == *rhs.rsa)return *this;

		rsa = new int[rhs.rsalen];
		rsalen = rhs.rsalen;
		for (int i = 0; i < rhs.count; ++i)
		{
			this->rsa[i] = rhs.rsa[i];
			count++;
		}
		return *this;
	}
	void Runtimesizearray::inflate(Runtimesizearray &rhs, int size = 10)
	{
		int *temp = new int[rhs.count+size];
		rsalen += size;
		for(int c = 0; c < rhs.count ; c++)
		{
			temp[c] = rhs.rsa[c];
		}
		free(rhs.rsa);
		rhs.rsa = temp;

	}
	void Runtimesizearray::readata()
	{
		cout << "Enter 10 elements: ";
		char c = 'n';
		int i = 0;
		count = 0;
		do{
			for (i; i < rsalen; ++i)
			{
				cin >> rsa[i];
				count++;
			}
			cout << "need to store more elements: y/n";
			cin >> c;
			if(c == 'y')
			{
				Runtimesizearray::inflate(*this);
			}
		}while(c == 'y' && count < MAX);
		
	}
	void Runtimesizearray::addelement()
	{
		int size;
		cout << "Enter number of elements to add";
		cin >> size;
		Runtimesizearray::inflate(*this, size);
		for (int i = count; i < count+size; ++i)
		 {
		 	cin >> rsa[i];
		 }
		 count += size; 
	}
	int Runtimesizearray::fetchelement(int i)
	{
		return rsa[i];
	}
	inline void Runtimesizearray::resetelement(int inital = 0, int final = 10)
	{
		for (int i = inital; i < final; ++i)
		{
			rsa[i] = 0;
		}
	}
	inline int Runtimesizearray::getmaxsize()
	{
		return MAX;
	}
	inline int Runtimesizearray::getelementcount()
	{
		return count;
	}
	Runtimesizearray::~Runtimesizearray()
	{
		free(rsa);
		rsa = NULL;
	}
}
using namespace space;
int Runtimesizearray::arraycount = 0;

int main()
{
	Runtimesizearray array1;
	array1.readata();
	int fourthelement = array1.fetchelement(3);
	cout<<"fourthelement: " << fourthelement<<endl;	
	int *arry = new int[10];

	Runtimesizearray array2(array1);
	cout <<"No. of elements in array2: " <<array2.getelementcount() << endl;
	array2.addelement();
	cout << "No. of elements in array2: " <<array2.getelementcount() << endl;

	int tmepar[] = {1,2,3,4,5,6,7,8,9};
	Runtimesizearray array3(tmepar, 10, 50);
	cout << "max elements in array3: "<< array3.getmaxsize() << endl;
}