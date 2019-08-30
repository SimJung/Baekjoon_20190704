#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool arr[51][51];
bool visit[51][51];
queue<pair<int, int>> q;
int m, n, k, answer, x, y;

void func(int a, int b)
{
	if (arr[a][b] && !visit[a][b])
	{
		visit[a][b] = 1;
		q.push(make_pair(a, b));
	}
}

void bfs()
{
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		if (xx > 0)
			func(xx - 1, yy);
		if (xx < n-1)
			func(xx + 1, yy);
		if (yy > 0)
			func(xx, yy - 1);
		if (yy < m-1)
			func(xx, yy + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;
		answer = 0;
		for (int i = 0; i < n; i++)
		{
			memset(arr[i], 0, sizeof(bool) * m);
			memset(visit[i], 0, sizeof(bool) * m);
		}

		for (int i = 0; i < k; i++)
		{
			cin >> y >> x;
			arr[x][y] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] && !visit[i][j])
				{
					answer++;
					visit[i][j] = 1;
					q.push(make_pair(i, j));
					bfs();
				}
			}
		}

		cout << answer << '\n';
	}
	return 0;
}