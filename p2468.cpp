#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int t, answer;
int arr[101][101];
bool visit[101][101];
queue<pair<int, int>> q;


void showarr();
void showvisit();
void bfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	int maxx=0, maxa=0;

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cin >> arr[i][j];
			
			if (maxx < arr[i][j])
				maxx = arr[i][j];
		}
	}

	for (int k = 0; k <= maxx; k++)
	{
		answer = 0;
		while (!q.empty())
			q.pop();

		for (int i = 1; i <= t; i++)
		{
			memset(visit[i], 0, sizeof(bool) * (t+1));
		}

		for (int i = 1; i <= t; i++)
		{
			for (int j = 1; j <= t; j++)
			{
				if (arr[i][j] > k && !visit[i][j])
				{
					answer++;
					visit[i][j] = 1;
					q.push(make_pair(i, j));
					bfs(k);
				}

			}
		}
		if (maxa < answer)
			maxa = answer;
	}
	

	//showarr();
	cout << maxa << '\n';
	return 0;
}

void bfs(int hh)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		

		if (x > 0)
		{
			if (arr[x - 1][y] > hh && !visit[x - 1][y])
			{
				q.push(make_pair(x - 1, y));
				visit[x-1][y] = 1;
			}
				
		}

		if (x < t)
		{
			if (arr[x + 1][y] > hh && !visit[x + 1][y])
			{
				q.push(make_pair(x + 1, y));
				visit[x + 1][y] = 1;
			}
		}

		if (y > 0)
		{
			if (arr[x][y-1] > hh && !visit[x][y-1])
			{
				q.push(make_pair(x, y - 1));
				visit[x][y - 1] = 1;
			}
		}

		if (y < t)
		{
			if (arr[x][y + 1] > hh && !visit[x][y + 1])
			{
				q.push(make_pair(x, y+1));
				visit[x][y+1] = 1;
			}
		}
	}
}

void showarr()
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void showvisit()
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
}