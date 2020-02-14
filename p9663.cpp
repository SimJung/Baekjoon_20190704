#include <iostream>
#include <stack>
#include <cstring>
#define pi pair<int, int>
using namespace std;

int n, ans;
stack<pi> s;
bool possible[15];
pi arr[15];

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool chk = false;
			for (int k = 0; k < n; k++) {
				if (arr[k].first == i && arr[k].second == j)
				{
					chk = true;
					break;
				}
			}
			if (chk)
				cout << "бс";
			else
				cout << "бр";
		}
		cout << '\n';
	}
}

void safe(int i) {
	memset(possible, 0, 15);
	for (int k = 0; k < i; k++) {
		possible[arr[k].second] = true;
		int v1 = arr[k].second - arr[k].first + i;
		int v2 = arr[k].first + arr[k].second - i;

		if (v1 >= 0 && v1 < n)
			possible[v1] = true;
		if (v2 >= 0 && v2 < n)
			possible[v2] = true;
	}

	for (int k = 0; k < n; k++) {
		if (!possible[k])
			s.push(make_pair(i, k));
	}
}

void queen() {
	for (int i = 0; i < n; i++) {
		s.push(make_pair(0, i));
	}

	while (!s.empty()) {
		pi p = s.top();
		arr[p.first] = p;
		s.pop();

		if (p.first == n-1) {
			ans++;
			//print();
			//cout<<'\n';
		}
		else {
			safe(p.first+1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	queen();

	cout << ans << '\n';

	return 0;
}