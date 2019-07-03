#include <iostream>
using namespace std;

pair<int, int> dun[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, h, w;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;
		dun[i].first = w;
		dun[i].second = h;
	}

	for (int i = 0; i < t; i++)
	{
		int rank = 1;
		for (int j = 0; j < t; j++)
		{
			if (i == j)
				continue;
			if (dun[i].first < dun[j].first && dun[i].second < dun[j].second)
				rank++;
		}
		if (i)
			cout << ' ';
		cout << rank;
	}
	cout << '\n';
	return 0;
}