#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y, c, h, k, ans, cnt;
bool visit[100001];
vector<int> v[100001], v2;

void dfs(int para)
{
	visit[para] = 1;
	cnt++;
	for (int i = 0; i < v[para].size(); i++)
	{
		if (!visit[v[para][i]])
			dfs(v[para][i]);
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
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> c >> h >> k;
	dfs(c);
	ans += cnt;
	dfs(h);

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			cnt = 0;
			dfs(i);
			v2.push_back(cnt);
		}
	}
	sort(v2.begin(), v2.end());
	for (int i = v2.size() - 1; i > v2.size() - 1 - k; i--) ans += v2[i];
	cout << ans << '\n';
	return 0;
}