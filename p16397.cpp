#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool visit[100000];
int tt[100000];
queue<int> q;
int n, t, g;

int bfs() {
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		if (n >= 50000 && g < 50000 && !tt[g])
			return -1;
		if (n == 99999 && !tt[g])
			return -1;
		if (n >= 100000)
			continue;

		if (!visit[n+1] || tt[n+1] > tt[n]+1)
		{
			tt[n + 1] = tt[n] + 1;
			visit[n + 1] = 1;
			q.push(n + 1);
		}
		
		string str_n = to_string(n*2);
		
		str_n[0] = (n == 0) ? str_n[0] : --str_n[0];
		int new_n = stoi(str_n);

		if (n < 50000)
		{
			if (!visit[new_n] || tt[new_n] > tt[n] + 1)
			{
				tt[new_n] = tt[n] + 1;
				visit[new_n] = 1;
				q.push(new_n);
			}
		}
	}
	if (tt[g] > t)
		return -1;
	else
		return tt[g];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> t >> g;
	q.push(n);
	visit[n] = 1;
	int ans = bfs();

	if (ans == -1)
		cout << "ANG\n";
	else
		cout << ans<<'\n';

	
	return 0;
}