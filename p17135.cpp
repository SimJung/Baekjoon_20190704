#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define PI pair<int, int>
using namespace std;

bool arr[16][16];
bool arr2[16][16];
bool visit[16][16];

int n, m, d, max_cnt, cnt;
int x[3];
queue<PI> q;
queue<PI> killList;

bool getVal(bool a[][16], PI p)
{
	return a[p.first][p.second];
}

void setVal(bool a[][16], PI p, bool val)
{
	a[p.first][p.second] = val;
}

int getDist(PI target, PI origin)
{
	return abs(target.first - origin.first) + abs(target.second - origin.second);
}

PI getTarget(PI a)
{
	PI ret = make_pair(-1, -1);

	q.push(make_pair(a.first - 1, a.second));
	setVal(visit, a, 1);

	while (!q.empty())
	{
		if (getDist(q.front(), a) > d)
		{
			while (!q.empty())
				q.pop();
			break;
		}
		if (getVal(arr, q.front()))
		{
			ret = q.front();
			while (!q.empty())
				q.pop();
			break;
		}
		else {

			bool chkP[3] = { false, false, false };
			PI p1;
			if (q.front().second > 1) {
				p1 = make_pair(q.front().first, q.front().second - 1);
				
				chkP[0] = true;
			}
			PI p2;
			if (q.front().first > 0) {
				p2 = make_pair(q.front().first - 1, q.front().second);
				
				chkP[1] = true;
			}
			PI p3;
			if (q.front().second < m) {
				p3 = make_pair(q.front().first, q.front().second + 1);
				
				chkP[2] = true;
			}
			q.pop();

			if (chkP[0] && !getVal(visit, p1)){
				q.push(p1);
				setVal(visit, p1, 1);
			}
			if (chkP[1] && !getVal(visit, p2)) {
				q.push(p2);
				setVal(visit, p2, 1);
			}
			if (chkP[2] && !getVal(visit, p3)) {
				q.push(p3);
				setVal(visit, p3, 1);
			}
		}
	}
	for (int i = 0; i < n; i++)
		memset(visit[i], 0, m+1);
	return ret;
}

void killMob(int y, int x)
{
	PI t = getTarget(make_pair(y, x));
	if (t.first != -1 && getVal(arr, t) == 1)
	{
		killList.push(t);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr2[i][j];
	}
	for (int i = 1; i <= m - 2; i++)
	{
		for (int j = i + 1; j <= m - 1; j++)
		{
			for (int k = j + 1; k <= m; k++)
			{
				cnt = 0;
				memcpy(arr, arr2, sizeof(arr));
				for (int ay = n; ay > 0; ay--)
				{
					killMob(ay, i);
					killMob(ay, j);
					killMob(ay, k);
					while (!killList.empty())
					{
						if (getVal(arr, killList.front()))
						{
							setVal(arr, killList.front(), 0);
							cnt++;
						}
						killList.pop();
					}
				}
				if (max_cnt < cnt) {
					max_cnt = cnt;
					x[0] = i; x[1] = j; x[2] = k;
				}
			}
		}
	}

	cout << max_cnt << '\n';
	return 0;
}