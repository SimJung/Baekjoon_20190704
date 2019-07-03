#include <iostream>
using namespace std;

int coin[4] = { 1, 2, 5, 7 };
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	dp[5] = 1;
	dp[7] = 1;

	for (int i = 3; i <= n; i++)
	{
		if(i != 5 && i != 7)
			dp[i] = dp[i - 1] + 1;
		if (i > 7 && dp[i - 7] + 1 < dp[i])
			dp[i] = dp[i - 7] + 1;
		if (i > 5 && dp[i - 5] + 1 < dp[i])
			dp[i] = dp[i - 5] + 1;
		if (i > 2 && dp[i - 2] + 1 < dp[i])
			dp[i] = dp[i - 2] + 1;
	}
	cout << dp[n] << '\n';
	return 0;
}