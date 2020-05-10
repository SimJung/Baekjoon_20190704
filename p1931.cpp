#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pi pair<int, int>

int n;
vector<pi> v;
bool cmp(pi a, pi b) {
	if(a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t_s, t_e, answer = 1, prevEnd = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t_s>>t_e;
		v.push_back(make_pair(t_s, t_e));
	}
	sort(v.begin(), v.end(), cmp);

	prevEnd = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= prevEnd) {
			answer++;
			prevEnd = v[i].second;
		}
	}
	cout << answer << '\n';
	return 0;
}