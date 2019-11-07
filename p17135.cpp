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
queue<PI> q;

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

void chkPush(PI a, PI t)
{
	if (getDist(a, t) <= d && !getVal(visit, t))
	{
		setVal(visit, t, true);
		q.push(t);
	}
}

void show(bool a[][16])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j]<<' ';
		}
		cout << '\n';
	}
}

PI getTarget(PI a)
{
	PI ret = make_pair(-1, -1);
	
	q.push(make_pair(a.first - 1, a.second));

	while (!q.empty())
	{
		if (getVal(arr, q.front()))
		{
			ret = q.front();
			q.pop();
			break;
		}
		else {
			PI p1 = make_pair(q.front().first, q.front().second - 1);
			PI p2 = make_pair(q.front().first - 1, q.front().second);
			PI p3 = make_pair(q.front().first, q.front().second + 1);
			q.pop();

			chkPush(a, p1); chkPush(a, p2); chkPush(a, p3);
		}
	}
	return ret;
}

void killMob(int y, int x)
{
	PI t = getTarget(make_pair(y, x));
	if (t.first != -1 && getVal(arr, t) == 1)
	{
		cnt++;
		setVal(arr, t, 0);
	}
}

void cpArr()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = arr2[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m>>d;
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
				cpArr();
				for (int l = 0; l < n; l++)
				{
					memset(visit[l], 0, m+1);
				}
				for (int ay = n; ay > 0; ay--)
				{
					killMob(ay, i);
					killMob(ay, j);
					killMob(ay, k);
				}
				max_cnt = (cnt > max_cnt) ? cnt : max_cnt;
			}
		}
	}

	cout << max_cnt << '\n';
	return 0;
}