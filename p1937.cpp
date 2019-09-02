#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[501][501];
int ks[501][501];
queue<pair<int, int>> q;
bool visit[501][501];
int t;

void chk(int i, int j, int x, int y)
{
	if (arr[i][j] < arr[x][y] && !visit[x][y])
	{
		visit[x][y] = 1;
		ks[x][y] = ks[i][j] + 1;
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
			chk(i, j)
		}
	}
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

		}
	}
	return 0;
}