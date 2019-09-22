#include <iostream>
using namespace std;

int n, maxx, prev_max = 0;
int arr[2][16];
int dp [16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[0][i] >> arr[1][i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j + arr[0][j] <= i && arr[1][i] + dp[j] > dp[i] && arr[0][i] + i <= n+1)
			{
				dp[i] = arr[1][i] + dp[j];
			}
		}
		if (dp[i] == 0 && arr[0][i] + i <= n+1)
			dp[i] = arr[1][i];

		maxx = (maxx < dp[i]) ? dp[i] : maxx;
	}


	cout << maxx << '\n';
	return 0;
}