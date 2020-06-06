#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	while (true)
	{

		cin >> t;
		if (t == 0)
			break;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (auto it : v) {
		cout << it << ' ';
	}
	cout << '\n';
	return 0;
}