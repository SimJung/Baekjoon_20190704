#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[1005][1005];	//방문 체크
bool chkempty = 1;
int map[1005][1005];	//초기 입력받는 토마토 상태
int map_data[1005][1005];//걸리는 시간 입력
int n, m, sum;
int maxx = -1;
queue<pair<int, int>> q;
int arr_x[] = { 0, 1, 0, -1 };
int arr_y[] = { 1, 0, -1, 0 };

void chkAns()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map_data[i][j] == 100000000)	//10000이면 안 익은 토마토
			{
				maxx = -1;
				return;
			}
			else if (map_data[i][j] != 100000001)	//10001이면 벽
				maxx = max(maxx, map_data[i][j]);
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int px = x + arr_x[i];
			int py = y + arr_y[i];

			if (px >= 0 && px < m && py >= 0 && py < n)
			{
				if (visit[px][py] == 0 && map[px][py] == 0)
				{
					visit[px][py] = 1;
					q.push(make_pair(px, py));
					map_data[px][py] = map_data[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(make_pair(i, j));	//익은 토마토 큐에 넣기
			sum += map[i][j];
		}
	}

	if (sum == n * m)	//처음부터 다 익었을 경우
	{
		cout << "0\n";
		return 0;
	}
	else if (sum == n * m*-1)	//전부 다 벽일 경우
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < m; i++)	//시간 나타내는 배열 초기화
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
				map_data[i][j] = 100000000;
			else if (map[i][j] == -1)
				map_data[i][j] = 100000001;
			else
				map_data[i][j] = 0;
		}
	}

	bfs();
	chkAns();
	cout << maxx << '\n';

	return 0;
}

