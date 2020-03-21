#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> dp[1001];
int ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	int pos;

	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++) {
		string::iterator it;
		for (it = str2.begin(); it != str2.end(); it++) {
			it = find(it, str2.end(), str1[i]);
			if (it == str2.end())
				break;
			pos = distance(str2.begin(), it);

			int dpval = 0;
			for (int j = 0; j < pos; j++) {
				if (dp[j].second < i+1 && dpval < dp[j].first) {
					dpval = dp[j].first;
				}
			}
			dp[pos].first = dpval + 1;
			dp[pos].second = i + 1;

			if (ans < dp[pos].first)
				ans = dp[pos].first;
		}
	}
	cout << ans << '\n';

	return 0;
}