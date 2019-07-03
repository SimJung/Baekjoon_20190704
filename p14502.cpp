#include <iostream>
#include <queue>
using namespace std;

int arr[9][9];
bool visit[9][9];
queue<pair<int, int>> q;
queue<pair<int, int>> tq;
int n, m, maxx;

int arr_x[] = { -1, 0, 1, 0 };
int arr_y[] = { 0, -1, 0, 1 };

void bfs()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < q.size(); i++)
		tq.push();
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
			if (arr[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				for (int l = 0; l < m; l++)
				{
					for (int x = 0; x < n; x++)
					{
						for (int y = 0; y < m; y++)
						{
							if (x == k && y == l)
								continue;
							if (x == i && y == j)
								continue;




						}
					}
					if (k == i && l == j)
						continue;
				}
			}
		}
	}

	return 0;
}