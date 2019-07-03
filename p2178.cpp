#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

bool visit[101][101];
bool map[101][101];
int map_data[101][101];
int n, m;

void bfs(int nn, int mm)
{
	visit[nn][mm] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(nn, mm));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x - 1 >= 0 && !visit[x-1][y] && map[x-1][y])
		{
			visit[x-1][y] = 1;
			q.push(make_pair(x - 1, y));
			map_data[x - 1][y] = min(map_data[x - 1][y], map_data[x][y] + 1);
		}

		if (x + 1 < n && !visit[x + 1][y] && map[x + 1][y])
		{
			visit[x + 1][y] = 1;
			q.push(make_pair(x + 1, y));
			map_data[x + 1][y] = min(map_data[x + 1][y], map_data[x][y] + 1);
		}

		if (y - 1 >= 0 && !visit[x][y-1] && map[x][y - 1])
		{
			visit[x][y - 1] = 1;
			q.push(make_pair(x, y - 1));
			map_data[x][y - 1] = min(map_data[x][y - 1], map_data[x][y] + 1);
		}

		if (y + 1 < m && !visit[x][y+1] && map[x][y+1])
		{
			visit[x][y+1] = 1;
			q.push(make_pair(x, y+1));
			map_data[x][y+1] = min(map_data[x][y+1], map_data[x][y] + 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strr;
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		cin >> strr;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = strr[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map_data[i][j] = 10001;
		}
	}
	map_data[0][0] = 1;
	bfs(0, 0);
	cout << map_data[n - 1][m - 1] << '\n';
	return 0;
}