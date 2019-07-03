#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first < b.first)
		return 1;
	else if (a.first > b.first)
		return 0;
	else {
		if (a.second < b.second)
			return 1;
		else
			return 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;

	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}