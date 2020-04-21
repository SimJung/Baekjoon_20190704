#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>
using namespace std;
#define ti tuple<int, int, int>

int n, m, h, des, cur, ans;
int arr[101][101][101];
bool visit[101][101][101];
queue<ti> q;

void showArr() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cout << setw(6)<<arr[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << "\n";
	}
	cout << "----------------------------------\n";
}

void bfs() {
	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front()), z = get<2>(q.front());
		q.pop();
		cur++;

		if (arr[x][y][z] - 1 > ans)
			ans = arr[x][y][z] -1;

		if (y > 0 && !visit[x][y - 1][z]) {
			visit[x][y - 1][z] = 1;
			q.push(make_tuple(x, y - 1, z));
			arr[x][y - 1][z] = arr[x][y][z] + 1;
		}
		if (y < m-1 && !visit[x][y + 1][z]) {
			visit[x][y + 1][z] = 1;
			q.push(make_tuple(x, y + 1, z));
			arr[x][y + 1][z] = arr[x][y][z] + 1;
		}
		if (x > 0 && !visit[x - 1][y][z]) {
			visit[x - 1][y][z] = 1;
			q.push(make_tuple(x - 1, y, z));
			arr[x - 1][y][z] = arr[x][y][z] + 1;
		}
		if (x < h - 1 && !visit[x + 1][y][z]) {
			visit[x + 1][y][z] = 1;
			q.push(make_tuple(x + 1, y, z));
			arr[x + 1][y][z] = arr[x][y][z] + 1;
		}
		if (z > 0 && !visit[x][y][z - 1]) {
			visit[x][y][z - 1] = 1;
			q.push(make_tuple(x, y, z - 1));
			arr[x][y][z - 1] = arr[x][y][z] + 1;
		}
		if (z < n - 1 && !visit[x][y][z + 1]) {
			visit[x][y][z + 1] = 1;
			q.push(make_tuple(x, y, z + 1));
			arr[x][y][z + 1] = arr[x][y][z] + 1;
		}

		//showArr();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m>>h;
	des = n * m * h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == -1){
					des--;
					visit[i][j][k] = 1;
				}
				else if (arr[i][j][k] == 1){
					cur++;
					q.push(make_tuple(i, j, k));
					visit[i][j][k] = 1;
				}
			}
		}
	}

	
	if (des == 0) {
		cout << "-1\n";
	}else if (cur == des) {
		cout << "0\n";
	}
	else {
		bfs();
		if (cur >= des)
			cout << ans << '\n';
		else
			cout << "-1\n";
	}
	
	return 0;
}