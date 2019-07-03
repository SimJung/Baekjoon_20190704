#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		//first가 중요도, second가 인덱스
		int n, m, c=1, p, max=0;
		int p_count[10] = { 0, };

		queue<pair<int, int>> q;
		cin >> n >> m;
		
		for (int i = 0; i < n; i++)
		{
			cin >> p;
			q.push(make_pair(p, i));
			p_count[p]++;
		}
		bool chk = false;

		while (!chk)
		{
			chk = false;
			for (int i = 9; i >= 0; i--)
			{
				if (p_count[i])
				{
					max = i;
					break;
				}
			}
			while (q.front().first != max)
			{
				int t1, t2;
				t1 = q.front().first;
				t2 = q.front().second;
				q.pop();
				q.push(make_pair(t1, t2));
			}
			if (q.front().second == m)
			{
				cout << c << '\n';
				chk = true;
				break;
			}
			else {
				c++;
				p_count[max]--;
				q.pop();
			}
		}
	}
	return 0;
}