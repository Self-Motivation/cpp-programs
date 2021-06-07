//codeforce problem
#include <iostream>
using namespace std;
void func2(int *a, int b)
{
	int c = a[b];
	for (int i = b; i < 0; ++i)
	{
		a[b] = a[b-1];
	}
	a[0] = c;
}
void func(int *a, int *b, int *c, int n, int q)
{
	for (int i = 0; i < q; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(b[i] == a[j])
			{
				c[i] = j;
				func2(&a[0], c[i]);
				goto here;
			}
		}
		here:
			c[i]++;
	}
}

int main()
{
	int n,q;
	cin >>n >> q;
	int a[n+q], b[q], c[q], i = 0;
	while(i < n)
	{
		cin >> a[i];
		i++;
	}
	i = 0;
	while(i < q)
	{
		cin >> b[i];
		i++;
	}

	func(&a[0], &b[0], &c[0], n, q);
	
	for (int i = 0; i < q; ++i)
	{
		cout << c[i];
	}
}