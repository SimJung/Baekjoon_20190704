#include <iostream>
#include <queue>
using namespace std;

bool arr[1001][1001];
bool visit[1001];
int n, m, v, x, y;

void dfs(int);
void bfs(int);
queue<int> bq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n>>m>>v;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(v);

	cout << '\n';
	for (int i = 0; i <= n; i++)
		visit[i] = false;

	bfs(v);


	return 0;
}

void dfs(int nn)
{
	visit[nn] = true;
	cout << nn << ' ';
	for (int i = 1; i <= n; i++) {
		if (arr[i][nn] && !visit[i])
		{
			dfs(i);
		}
	}
}

void bfs(int nn)
{
	visit[nn] = true;
	bq.push(nn);

	while (!bq.empty())
	{
		int temp = bq.front();
		bq.pop();
		cout << temp << ' ';

		for (int i = 1; i <= n; i++)
		{
			if (arr[temp][i] && !visit[i])
			{
				visit[i] = true;
				bq.push(i);
			}
		}
	}
}