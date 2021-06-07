//finding best price using dynamic programming
#include <iostream>

using namespace std;

int func(int *prices, int n)
{
	int *np = new int[n+1];
	for (int i = 0; i < n; ++i)
	{
		np[i+1] = prices[i];
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout << np[i] << " ";
	// }
	int *dp = new int[n+1];
	dp[0] = 0;
	dp[1] = np[1];
	for (int i = 2; i < n+1; ++i)
	{
		dp[i] = np[i];
		int li = 1;
		int ri = i-1;
		while(li <= ri)
		{
			if(dp[li]+dp[ri] > dp[i])
			{
				dp[i] = dp[li] + dp[ri];
			}
			li++;
			ri--;
		}
	}
// 	for(int i = 0; i<=n; i++)
// 	{
// 	    cout << dp[i] << " ";
// 	}
// 	return dp[n];
}

int main()
{
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	cout <<endl <<func(&prices[0],8);

}