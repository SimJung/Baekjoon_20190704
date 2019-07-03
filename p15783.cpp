#include <iostream>
#include <vector>
using namespace std;

bool visit[100001];
int n, m, a, b, virus;
vector<int> v[100001];

void dfs(int num)
{
	visit[num] = 1;
	for (int i = 0; i < v[num].size(); i++)
	{
		if (!visit[v[num][i]])
			dfs(v[num][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--)
	{
		cin >> a >> b;
		if (a > b)
			v[b].push_back(a);
		else
			v[a].push_back(b);
	}

	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			virus++;
			dfs(i);
		}
	}

	cout << virus << '\n';

	return 0;
}