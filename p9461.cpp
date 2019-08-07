#include <iostream>
using namespace std;

long long int dp[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	while (t--)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
	
	return 0;
}