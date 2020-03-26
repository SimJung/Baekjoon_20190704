#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int ans = 0;
string str1, str2;
int dp[1001][1001];

void show() {
	for (int i = 0; i <= str1.length(); i++)
	{
		for (int j = 0; j <= str2.length(); j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> str1 >> str2;

	int big1 = 0;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			big1 = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = big1;
			}
		}
	}
	cout << dp[str1.length()][str2.length()] << '\n';

	return 0;
}