#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ro {
	int r;
	int c;
	int s;
};

int n, m, k, summin = 50001;
int arr[51][51], origin[51][51];
ro r[6];
queue<int> q;

void rotate(int r, int c, int s) {
	for (int i = 1; i <= s; i++) {
		for (int j = c-i; j <= c + i-1; j++) {
			q.push(arr[r - i][j]);
		}

		for (int j = r-i; j <= r + i-1; j++) {
			q.push(arr[j][c + i]);
		}

		for (int j = c+i; j >= c - i+1; j--) {
			q.push(arr[r + i][j]);
		}

		for (int j = r+i; j >= r - i+1; j--) {
			q.push(arr[j][c - i]);
		}


		for (int j = c - i+1; j <= c + i; j++) {
			arr[r - i][j] = q.front();
			q.pop();
		}

		for (int j = r - i+1; j <= r + i; j++) {
			arr[j][c+i] = q.front();
			q.pop();
		}

		for (int j = c + i-1; j >= c - i; j--) {
			arr[r + i][j] = q.front();
			q.pop();
		}

		for (int j = r + i - 1; j >= r - i; j--) {
			arr[j][c - i] = q.front();
			q.pop();
		}
	}
}

void getMin() {
	int sum_h = 0;
	for (int i = 1; i <= n; i++) {
		sum_h = 0;
		for (int j = 1; j <= m; j++) {
			sum_h += arr[i][j];
		}
		if (summin > sum_h) {
			summin = sum_h;
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
	for (int i = 0; i < k; i++)
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
		for (int i = 0; i < v.size(); i++) {
			rotate(r[v[i]].r, r[v[i]].c, r[v[i]].s);
		}
		
		getMin();
		
	} while (next_permutation(v.begin(), v.end()));

	cout << summin << '\n';
	return 0;
}