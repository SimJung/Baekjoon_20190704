#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pi pair<int, int>

int dp[100001];
vector<pi> val;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, w, v, ans=0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		val.push_back(make_pair(w, v));
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i + val[j].first > k)
				continue;

			if (dp[i + val[j].first] < dp[i] + val[j].second) {
				dp[i + val[j].first] = dp[i] + val[j].second;
				if (ans < dp[i + val[j].first])
					ans = dp[i + val[j].first];
			}
		}
	}

	cout << ans << '\n';
	return 0;
}