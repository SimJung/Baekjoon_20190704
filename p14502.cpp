#include <iostream>
#include <queue>
#define pi pair<int, int>
using namespace std;

int arr[9][9], firstLab[9][9], ans, now_res, wall;
bool visit[9][9], walls[9][9];
queue<pi> q;
queue<pi> virus;
int n, m;

void showInit() {
	cout << "------------------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << walls[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << firstLab[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "------------------------------------------------------\n";
}

void showNow() {
	cout << "------------------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "------------------------------------------------------\n";
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = walls[i][j];
			arr[i][j] = firstLab[i][j];
		}
	}

	q = virus;
	now_res = 0;
}

void bfs()
{
	if (wall < 3) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (firstLab[i][j] == 0) {
					walls[i][j] = 1; firstLab[i][j] = 1; wall++;
					bfs();
					walls[i][j] = 0; firstLab[i][j] = 0; wall--;
				}
			}
		}
	}
	else {
		init();
		while (!q.empty()) {
			pi vp = q.front();
			q.pop();

			if (vp.first > 0 && !visit[vp.first - 1][vp.second]) {
				visit[vp.first - 1][vp.second] = 1;
				arr[vp.first - 1][vp.second] = 2;
				q.push(make_pair(vp.first - 1, vp.second));
			}

			if (vp.second > 0 && !visit[vp.first][vp.second - 1]) {
				visit[vp.first][vp.second - 1] = 1;
				arr[vp.first][vp.second - 1] = 2;
				q.push(make_pair(vp.first, vp.second - 1));
			}

			if (vp.first < n-1 && !visit[vp.first+1][vp.second]) {
				visit[vp.first+1][vp.second] = 1;
				arr[vp.first+1][vp.second] = 2;
				q.push(make_pair(vp.first+1, vp.second));
			}

			if (vp.second < m - 1 && !visit[vp.first][vp.second + 1]) {
				visit[vp.first][vp.second + 1] = 1;
				arr[vp.first][vp.second + 1] = 2;
				q.push(make_pair(vp.first, vp.second + 1));
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0)
					now_res++;
			}
		}

		if (ans < now_res) {
			ans = now_res;
		}

		init();
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2){
				virus.push(make_pair(i, j));
				walls[i][j] = 1;
				firstLab[i][j] = 2;
			}
			else if (arr[i][j] == 1) {
				walls[i][j] = 1;
				firstLab[i][j] = 1;
			}
		}
	}

	init();
	bfs();
	cout << ans << '\n';

	return 0;
}