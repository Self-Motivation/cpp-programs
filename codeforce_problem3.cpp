//codeforce problem solution
#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >>n >> m;
	int a[n], b[m], c[m], q, i = 0;
	while(i < n)
	{
		cin >> a[i];
		i++;
	}
	cin >> q;
	int z[q][2];
	for (i = 0; i < q; ++i)
	{
		cin >> z[i][0] >> z[i][1];
	}

	for (int i = 0; i < q; ++i)
	{
		if(z[i][0] - z[i][1] == -1 )
		{
			cout << "B";
		}else{
			cout << "A";
		}
	}
}