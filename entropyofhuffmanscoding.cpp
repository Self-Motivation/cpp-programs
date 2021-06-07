#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a[] = {0.32,0.25,0.16,0.12,0.1,0.05};

	float k;
	for (int i = 0; i < 5; ++i)
	{
		k += -(a[i]* log(a[i]));
	}
	cout << k;

}