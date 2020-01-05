#include <iostream>
#include <cstring>
using namespace std;

bool lines[1001][1001];
bool visit[1001];
int n, m;

void dfs(int k) {
	for (int i = 1; i <= n; i++) {
		if (lines[k][i] && !visit[i] && i!=k) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

void toggleLine(int l) {
	for (int j = 1; j <= n; j++) {
		if (l != j) {
			lines[l][j] = lines[l][j]?0:1;
			lines[j][l] = lines[l][j];
		}
	}
}

void showLines() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << lines[i][j] << ' ';
		}
		cout << '\n';
	}
}

void showVisit() {
	for (int i = 1; i <= n; i++)
		cout << visit[i] << ' ';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		lines[x][y] = 1;
		lines[y][x] = 1;
	}

	bool chk = 1;
	for (int i = 1; i <= n; i++) {
		chk = true;
		cout << "Before toggle\n";
		showLines();
		toggleLine(i);
		cout << "\nAfter toggle\n";
		showLines();
		cout << "\n";
		dfs(1);
		showVisit();
		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				cout << "NE\n";
				return 0;
			}
		}
		toggleLine(i);
		memset(visit, 0, n + 1);
	}
	cout << "DA\n";
	return 0;
}