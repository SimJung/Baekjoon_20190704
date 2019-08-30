#include <iostream>
#include <cstring>
using namespace std;

bool arr[101][101];
bool visit[101];
bool answer[101][101];
int t;

void dfs(int i)
{
	for (int j = 1; j <= t; j++)
	{
		if (arr[i][j] && !visit[j])
		{
			visit[j] = 1;
			dfs(j);
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
		dfs(i);
		for (int j = 1; j <= t; j++)
		{
			if (visit[j] == 1)
				answer[i][j] = 1;
		}
		memset(visit, 0, t+1);
	}

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}