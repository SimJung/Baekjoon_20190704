#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool visit[100000];
int tt[100000];
queue<int> q;
int on, t, g;
bool chk = true;

int bfs() {
	if (on == g)
		return 0;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		if (n >= 50000 && g < 50000 && !tt[g])
			continue;
		if (n == 99999 && !tt[g])
			continue;
		if (n >= 100000 || tt[n] > t)
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
		/*if (chk)
		{
			cout << n << endl;
			cout << n+1 << " : " << tt[n+1] << '\n';
			cout << new_n << " : " << tt[new_n] << "\n\n";
			if (n == g)
				chk = 0;
		}*/
	}
	if (tt[g] > t || tt[g] == 0)
		return -1;
	else
		return tt[g];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> on >> t >> g;
	q.push(on);
	visit[on] = 1;
	int ans = bfs();

	if (ans == -1 || tt[g] > t)
		cout << "ANG\n";
	else
		cout << ans<<'\n';

	
	return 0;
}