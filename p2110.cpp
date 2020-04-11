#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c, temp, l, r, m, prev_position, cnt;
	cin >> n>>c;

	for(int i=0; i<n; i++){
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	l = 0;
	r = v[v.size() - 1]+1;
	prev_position = v[0];

	while (l <= r) {
		cnt = 1;
		prev_position = v[0];
		m = (l + r) / 2;

		for (int i = 1; i < v.size(); i++) {
			if (v[i] >= prev_position + m) {
				prev_position = v[i];
				cnt++;
			}
		}

		if (cnt < c) {
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	
	cout << r << '\n';

	return 0;
}