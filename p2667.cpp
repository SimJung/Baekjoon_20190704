#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q;
bool arr[26][26];
bool visit[26][26];

int t;
int answer;
int ansarr[1001];

void op_bfs(int a1, int a2)
{
	if (arr[a1][a2] && !visit[a1][a2])
	{
		visit[a1][a2] = 1;
		ansarr[answer]++;
		q.push(make_pair(a1, a2));
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
			op_bfs(x - 1, y);
		if (x < t)
			op_bfs(x + 1, y);
		if (y > 0)
			op_bfs(x, y - 1);
		if (y < t)
			op_bfs(x, y + 1);

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	string st;

	for (int i = 1; i <= t; i++)
	{
		cin >> st;
		for (int j = 1; j <= st.length(); j++)
		{
			arr[i][j] = st[j - 1]-'0';
		}
	}

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (arr[i][j] && !visit[i][j])
			{
				answer++;
				visit[i][j] = 1;
				q.push(make_pair(i, j));
				ansarr[answer]++;
				bfs();
			}
		}
	}

	sort(&ansarr[1], &ansarr[answer + 1]);

	cout << answer << '\n';
	for (int i = 1; i <= answer; i++)
	{
		cout << ansarr[i] << '\n';
	}
	
	return 0;
}