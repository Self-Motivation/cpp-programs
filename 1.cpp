//code for codeforce educational round
#include <iostream>

using namespace std;
bool fn(long long int r,long long int b ,long long int d)
{
	if(r <= 0|| b<=0)return false;
	
	if(r>b)
	{
	    long long int temp = r;
	    r = b;
	    b = temp;
	}
	if(b<=(r*(1+d)))return true;
	return false;
}

int main()
{
	int t;
	cin >> t;
	long long int r, b, d;
	bool a[t];
	for (int i = 0; i < t; ++i)
	{
		cin >>r  >>b >>d;
		a[i] = fn(r, b ,d);
	}
		for (int i = 0; i<t; i++)
	{
	    if(a[i])
	    {
	        cout << "YES" << endl;
	    }else{
	        cout << "NO"  << endl;
	    }
	}
}