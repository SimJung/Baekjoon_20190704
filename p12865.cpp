#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weights[100001];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, w, v, ans=0;
	cin >> n >> k;

	vector<pair<int, int>> pv;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		pv.push_back(make_pair(w, v));
		weights[w] = v;
		if (ans < v && w <= k)
			ans = v;
	}

	sort(pv.begin(), pv.end());

	for (int i = 0; i <= k; i++) {
		if (i + pv[0].first > k) {
			break;
		}
		for (int j = 0; j < n; j++) {
			if (weights[i] + weights[pv[j].first] > weights[i + pv[j].first]) {
				weights[pv[j].first + i] = weights[i] + weights[pv[j].first];
				if (ans < weights[pv[j].first + i] && pv[j].first + i <= k)
					ans = weights[pv[j].first + i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}