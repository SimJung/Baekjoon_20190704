#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r[40001];
vector<int> lis;

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

	lis.push_back(r[1]);
	for (int i = 2; i <= t; i++) {
		auto val = lower_bound(lis.begin(), lis.end(), r[i]);
		if (val == lis.end()) {
			lis.push_back(r[i]);
		}
		else {
			*val = r[i];
		}
	}

	cout << lis.size() << '\n';
	return 0;
}