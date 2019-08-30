#include <iostream>
using namespace std;

bool arr[101][101];
bool visit[101];
bool answer[101][101];
int t;

void dfs(int i, int j)
{
	answer[i][j] = 1;
	for (int k = 1; k <= t; k++)
	{
		if (arr[j][k] && !visit[k])
		{
			answer[i][k] = 1;
			visit[k] = 1;
			dfs(j, k);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> t;
	
	bool n;

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cin >> n;
			if (n)
				arr[i][j] = 1;
		}
	}

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (arr[i][j] && !visit[j])
			{
				visit[j] = 1;
				dfs(i, j);
			}
		}
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