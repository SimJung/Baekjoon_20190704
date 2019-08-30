#include <iostream>
#include <vector>
using namespace std;

int n, m, u, v, ans;
bool arr[1001][1001];
bool visit[1001];

void dfs(int i)
{
	visit[i] = 1;
	for (int k = 1; k <= n; k++)
	{
		if (arr[i][k] && !visit[k])
			dfs(k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			ans++;
			dfs(i);
		}
	}
	cout << ans << '\n';

	return 0;
}