#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sq;
bool paper[101][101];
int m, n, k, area = 0;

void dfs(int p1, int p2) {
	paper[p1][p2] = 1;
	area++;

	if (p2 > 0 && !paper[p1][p2-1]) {
		dfs(p1, p2 - 1);
	}

	if (p2 + 1 < n && !paper[p1][p2 + 1]) {
		dfs(p1, p2 + 1);
	}

	if (p1 > 0 && !paper[p1 - 1][p2]) {
		dfs(p1 - 1, p2);
	}

	if (p1 < m -1 && !paper[p1 + 1][p2]) {
		dfs(p1 + 1, p2);
	}
}

void show() {
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			cout << paper[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int jj = y1; jj < y2; jj++) {
				paper[jj][j] = 1;
			}
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (!paper[i][j]) {
				dfs(i, j);
				sq.push_back(area);
				area = 0;
			}
		}
	}

	sort(sq.begin(), sq.end());
	cout << sq.size() << '\n';
	for (int i = 0; i < sq.size(); i++)
		cout << sq[i] << ' ';
	cout << '\n';
	
	return 0;
}