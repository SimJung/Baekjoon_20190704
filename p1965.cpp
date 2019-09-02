#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2000000000

int box[1001];

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.push_back(-INF);
	int t, ans=0;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> box[i];
	}

	for (int i = 1; i <= t; i++)
	{
		if (v.back() < box[i])
		{
			ans++;
			v.push_back(box[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), box[i]);
			*it = box[i];
		}
	}
	cout << ans << '\n';
	return 0;
}