#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	ans = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < t; i++) {
		dp[i] = dp[i - 1] + arr[i];
		for (int j = 0; j < i; j++) {
			if (dp[i] - dp[j] > ans)
				ans = dp[i] - dp[j];
		}
	}

	cout << ans << '\n';
	return 0;
}