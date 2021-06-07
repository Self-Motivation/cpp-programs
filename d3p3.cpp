//implementation of d3p2 i.e. dynamic array using template 
#include <iostream>

using namespace std;

namespace space{
	template <typename T>
	class Runtimesizearray
	{
	private:
		
		T *rsa;
		int MAX;
		static int getcount;
	public:
		Runtimesizearray();
		Runtimesizearray(int);
		Runtimesizearray(const Runtimesizearray&);
		Runtimesizearray(T *, int);

		//Runtimesizearray & operator=(const Runtimesizearray &);
		void inflate(T*, int );
		void readata();
		void addelement();
		int fetchelement(int);
		void resetelement(int, int);
		int getmaxsize();
		int getelementcount();
		~Runtimesizearray();
		
	};
	template <typename T>
	Runtimesizearray<T>::Runtimesizearray()
	{
		rsa = new T[10];
		MAX = 100;
	}
	template <typename T>
	Runtimesizearray<T>::Runtimesizearray(int max)
	{
		rsa = new int[10];
		MAX = max;
	}
	template <typename T>
	Runtimesizearray<T>::Runtimesizearray(T *array, int max)
	{
		rsa = new T[sizeof(array)/sizeof(int)+1];
		for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
		{
			rsa[i] = array[i];
		}
		MAX = max;
	}
	template <typename T>
	Runtimesizearray<T>::Runtimesizearray(const Runtimesizearray &rhs)
	{
		rsa = new int[sizeof(rhs.rsa)/sizeof(int)+1];
		for (int i = 0; i < getcount; ++i)
		{
			this->rsa[i] = rhs.rsa[i];
			getcount++;
		}
	}
	//assignment operator is not running giving error 
	//Runtimesizearray &rhs must be a non-static membered
	// Runtimesizearray & operator=(const Runtimesizearray &rhs)
	// {
	// 	if(this->rsa == rhs.rsa)return this;

	// 	rsa = new int[sizeof(rhs.rsa)/sizeof(int)+1];
	// 	for (int i = 0; i < getcount; ++i)
	// 	{
	// 		this->rsa[i] = rhs.rsa[i];
	// 		getcount++;
	// 	}
	// }
	template <typename T>
	void Runtimesizearray<T>::inflate(T* rhs, int size)
	{
		T *temp = new T[getelementcount()+size];
		for(int c = 0; c < getelementcount() ; c++)
		{
			temp[c] = rhs[c];
		}
		free(rhs);
		rhs = temp;
	}
	template <typename T>
	void Runtimesizearray<T>::readata()
	{
		char c = 'n';
		int i = 0;
		do{
			for (i; i < 10; ++i)
			{
				cin >> rsa[i];
				getcount++;
			}
			cout << "need to store more elements: y/n";
			cin >> c;
			if(c == 'y')
			{
				inflate(this->rsa, 10);
			}
		}while(c == 'y' && getcount < MAX);
		
	}
	template <typename T>
	void Runtimesizearray<T>::addelement()
	{
		int size;
		cout << "Enter number of elements to add";
		cin >> size;
		inflate(this->rsa, size);
		for (int i = getcount; i < size; ++i)
		 {
		 	cin >> rsa[i];
		 	getcount++;
		 } 
	}
	template <typename T>
	int Runtimesizearray<T>::fetchelement(int i)
	{
		return rsa[i];
	}
	template <typename T>
	void Runtimesizearray<T>::resetelement(int inital, int final)
	{
		for (int i = inital; i < final; ++i)
		{
			rsa[i] = 0;
		}
	}
	template <typename T>
	int Runtimesizearray<T>::getmaxsize()
	{
		return MAX;
	}
	template <typename T>
	int Runtimesizearray<T>::getelementcount()
	{
		return getcount;
	}
}
using namespace space;

int main()
{
	Runtimesizearray <int>array1;
	array1.readata();
	int fourthelement = array1.fetchelement(3);
	cout<<"fourthelement: " << fourthelement<<endl;	

	Runtimesizearray <int>array2(array1);
	cout <<"No. of elements in array2" <<array2.getelementcount();
	array2.addelement();
	cout << "No. of elements in array2" <<array2.getelementcount();

	float tmepar[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	Runtimesizearray <float>array3(tmepar, 50);
	cout << "max elements in array3: "<< array3.getmaxsize();
}