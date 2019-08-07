#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans=0;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> arr[i];
	}

	dp[1][0] = 1;
	dp[1][1] = 1;
	ans = 1;

	for (int i = 2; i <= t; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i][0] = max(dp[i][0], dp[j][0]);
				dp[i][1] = max(dp[i][1], dp[j][0]);
				
			}
			else if (arr[i] < arr[j])
			{
				dp[i][1] = max(dp[i][1], dp[j][1]);
			}
		}
		dp[i][0]++;
		dp[i][1]++;
		ans = max(max(dp[i][0], dp[i][1]), ans);
	}

	/*cout << "\n";
	for (int i = 1; i <= t; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= t; i++)
	{
		cout << dp[i][0] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= t; i++)
	{
		cout << dp[i][1] << ' ';
	}
	cout << '\n';*/
	
	cout << ans << '\n';
	return 0;
}