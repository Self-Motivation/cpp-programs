//codeforce educational round problem solution
//finding the max number of likes from 2 different sites with manipulation
#include <iostream>
using namespace std;
int func(int *a, int n)
{
	int i1[2] = {0,0}, i2[2] = {0,0};
	for (int i = 0; i < n; ++i)
	{
		if(a[i] == 1)
		{
			if(i1[0] == i2[0]){
				i1[0]++;
			}else{			
				(i1[0]>i2[0])?(i1[0]++):i2[0]++;
			}
		}
		else if(a[i] == 2)
		{
			if(i1[0] == i2[0]){
				i2[1]++;
			}else{
				(i1[0]>i2[0]) ? i2[1]++ : i1[1]++;
			}
			
			
		}
		else if(a[i] == 3)
		{
			if(i1[0] == i2[0]){
				i1[0]++;
			}
			else{
				(i1[0]>i2[0]) ? (i1[0]++) : i2[0]++;
			}
			
		}
	}
	return (i1[0]>=i2[0])? i1[0] : i2[0];
}

int main()
{
	int t;
	cin >>t;
	int n[t], a, i;

	for(int j = 0; j<t; j++){
		cin >> a;
		int b[a];
		i = 0;
		while (i<a)
		{
			cin >> b[i];
			i++;
		}
		// cout << b[0] <<endl<< a << endl;
		n[j] = func(&b[0], a);
		// cout << n[j] << endl;
	} 
	for(i = 0; i<t; i++)
	{
	    cout << n[i] << endl;
	}
}