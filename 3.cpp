//code for codeforce programs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fn(long long int *r,long long int *b ,long int n, int **arr)
{
	vector<vector<int>> vec(n);
	for (int i = 0; i < n; ++i)
	{
		vec[r[i]].push_back(b[i]);

	}
	for (int i = 0; i < n; ++i)
	{
		sort(vec.begin(), vec.end(), greater <>());
	}
	for (int i = 0; i < n&& (vec[i].size()!= 0); ++i)
	{

		for (int j = 0; j < vec.size()-(vec.size()%j); ++j)
		{
			arr[i][j] += vec[i][j];
		}
	}
}

int main()
{
	int t;
	cin >> t;
	long int n;
	int **arr;
	int conter[t];
	arr = new int*[t];
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		int count = 0;
		*arr = new int[n];
		conter[i] = n;
		long long int b[n], c[n];
		while(count < n)
		{
			cin >> b[count];
			count++;
		}
		count = 0;
		while(count < n)
		{
			cin >> c[count];
			count++;
		}
		fn(&b[0], &c[0], n, arr);
	}
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < conter[i]; ++j)
		{
			cout << arr[i][j];
		}
		
	}
}