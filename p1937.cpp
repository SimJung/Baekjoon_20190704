#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[501][501];
int ks[501][501];
queue<pair<int, int>> q;
bool visit[501][501];
int t, k;

void chk(int i, int j, int x, int y)
{
	if (arr[i][j] < arr[x][y] && !visit[x][y])
	{
		visit[x][y] = 1;
		ks[x][y] = ks[i][j] + 1;
		if (k < ks[x][y])
			k = ks[x][y];
		q.push(make_pair(x, y));
	}
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (x > 0)
		{
			chk(x, y, x - 1, y);
		}
		if (x < t)
		{
			chk(x, y, x + 1, y);
		}
		if (y > 0)
		{
			chk(x, y, x, y - 1);
		}
		if (y < t)
		{
			chk(x, y, x, y + 1);
		}
	}
}

void showks()
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cout << ks[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			for (int kk = 0; kk <= t; kk++)
			{
				memset(ks[kk], 0, (t+1)*sizeof(int));
				memset(visit[kk], 0, (t + 1));
			}
			ks[i][j] = 1;
			visit[i][j] = 1;
			q.push(make_pair(i, j));
			bfs();
		}
	}
	cout << k << '\n';
	return 0;
}

