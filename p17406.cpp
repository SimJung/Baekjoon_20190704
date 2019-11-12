#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ro {
	int r;
	int c;
	int s;
};

int n, m, k;
int arr[51][51], origin[51][51];
ro r[6];

void rotate(int r, int c, int s) {
	for (int i = r - s; i < r + s; i++) {
		for (int j = c - s; j < c + s; j++) {

		}
	}
}

int getMin() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
		v.push_back(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> origin[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> r[i].r >> r[i].c >> r[i].s;
	}

	do {
		memcpy(arr, origin, sizeof(arr));
		for (int i = 0; i < v.size(); i++)
			rotate(r[i].r, r[i].c, r[i].s);
		
		
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}