#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= t; i++)
	{
		dp[i] = dp[i - 1] % 15746 + dp[i - 2] % 15746;
		dp[i] %= 15746;
	}
	cout << dp[t] << '\n';
	return 0;
}