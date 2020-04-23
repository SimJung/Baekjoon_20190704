#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define ti tuple<int, int, int>

int n, m, h, ans = 0;
//접근할 때는 높이, 세로, 가로 순으로
int arr[101][101][101];
bool visit[101][101][101];
queue<ti> q;

void bfs() {
	while (!q.empty()) {
		// 0 번째 element, 높이
		int th = get<0>(q.front());

		// 1 번째 element, 세로
		int ty = get<1>(q.front());

		// 2 번째 element, 가로
		int tx = get<2>(q.front());
		q.pop();

		if (th > 0 && !visit[th - 1][ty][tx]) {
			visit[th - 1][ty][tx] = 1;
			arr[th - 1][ty][tx] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th - 1, ty, tx));
		}
		if (th < h-1 && !visit[th + 1][ty][tx]) {
			visit[th + 1][ty][tx] = 1;
			arr[th + 1][ty][tx] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th + 1, ty, tx));
		}

		if (ty > 0 && !visit[th][ty - 1][tx]) {
			visit[th][ty - 1][tx] = 1;
			arr[th][ty - 1][tx] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th, ty - 1, tx));
		}
		if (ty < n - 1 && !visit[th][ty + 1][tx]) {
			visit[th][ty + 1][tx] = 1;
			arr[th][ty + 1][tx] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th, ty + 1, tx));
		}

		if (tx > 0 && !visit[th][ty][tx - 1]) {
			visit[th][ty][tx - 1] = 1;
			arr[th][ty][tx - 1] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th, ty, tx - 1));
		}
		if (tx < m - 1 && !visit[th][ty][tx + 1]) {
			visit[th][ty][tx + 1] = 1;
			arr[th][ty][tx + 1] = arr[th][ty][tx] + 1;
			q.push(make_tuple(th, ty, tx + 1));
		}

		if (ans < arr[th][ty][tx] - 1)
			ans = arr[th][ty][tx] - 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					visit[i][j][k] = 1;
				}
				else if (arr[i][j][k] == -1)
					visit[i][j][k] = 1;
			}
		}
	}

	if (q.empty()) {
		cout << "-1\n";
	}
	else {
		bfs();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (arr[i][j][k] == 0)
					{
						cout << "-1\n";
						return 0;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}