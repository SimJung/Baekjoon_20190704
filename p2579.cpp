#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];

//0번 : 전전만 밟고 현재 밟은 상태, 1번 : 바로 전 밟고 현재 밟은 상태
int dp[301][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];

	dp[1][0] = arr[1];
	dp[1][1] = arr[1] + dp[0][0];

	for (int i = 2; i < t; i++)
	{
		dp[i][0] = max(dp[i - 2][1], dp[i-2][0]) + arr[i];
		dp[i][1] = dp[i - 1][0] + arr[i];
	}



	cout << max(dp[t-1][0], dp[t-1][1]) << '\n';
	return 0;
}