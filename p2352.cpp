#include <iostream>
using namespace std;

int r[40001];
int dp[40001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> r[i];
	}
	return 0;
}