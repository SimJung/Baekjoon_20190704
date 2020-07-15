#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int coins[101];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++){
		cin >> coins[i];
		dp[coins[i]] = 1;
	}

	sort(coins, coins + n);

	for (int i = 1; i <= k; i++) {

	}
	return 0;
}