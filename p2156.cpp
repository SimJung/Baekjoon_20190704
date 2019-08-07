#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

//0번 : 이전 잔 안 마심
//1번 : 이 잔이 연속 두 잔째(다음 잔 못마심)
int dp[10001][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, b_max=0, ans = 0;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> arr[i];
	}

	dp[1][0] = arr[1];
	dp[1][1] = arr[1];
	ans = arr[1];
	b_max = arr[1];

	if (t >= 2)
	{
		dp[2][0] = arr[2];
		dp[2][1] = arr[1] + arr[2];
		ans = dp[2][1];
	}

	for (int i = 3; i <= t; i++)
	{
		b_max = max(max(dp[i - 2][0], dp[i - 2][1]), b_max);
		dp[i][0] = b_max + arr[i];
		dp[i][1] = dp[i-1][0] + arr[i];
		ans = max(max(dp[i][0], dp[i][1]), ans);
	}

	/*for (int i = 1; i <= t; i++)
	{
		cout << i<<" : "<<dp[i][0] << ' '<<dp[i][1]<<'\n';
	}*/

	cout << ans << '\n';
	return 0;
}