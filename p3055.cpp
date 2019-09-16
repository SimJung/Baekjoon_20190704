#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int t[51][51];

vector<string> m;
vector<vector<bool>> visit_water;
vector<vector<bool>> visit_gosm;
int r, c, water_cnt, gosm_cnt=1;
pair<int, int> dest;
pair<int, int> gosm;
queue<pair<int, int>> g;
queue<pair<int, int>> w;

void show()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << visit_gosm[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\n\n";
}

void func_water(int x, int y)
{
	if ((m[x][y] == '.' || m[x][y] == 'S') && !visit_water[x][y])
	{
		visit_water[x][y] = 1;
		m[x][y] = '*';
		w.push(make_pair(x, y));
		water_cnt++;
	}
}

void func_gosm(int x, int y, int tt)
{
	if ((m[x][y] == '.' || m[x][y] == 'D') && (!visit_gosm[x][y] && !visit_water[x][y]))
	{

		visit_gosm[x][y] = 1;
		m[x][y] = 'S';
		t[x][y] = tt+1;
		gosm_cnt++;
		g.push(make_pair(x, y));
	}
}

int bfs()
{
	while (!g.empty())
	{
		int cnt = water_cnt;
		water_cnt = 0;
		for (int i = 0; i < cnt; i++)
		{
			int x1 = w.front().first;
			int y1 = w.front().second;

			w.pop();

			if (x1 > 0)
				func_water(x1 - 1, y1);
			if (x1 < r-1)
				func_water(x1 + 1, y1);
			if (y1 > 0)
				func_water(x1, y1 - 1);
			if (y1 < c - 1)
				func_water(x1, y1 + 1);
		}
		
		cnt = gosm_cnt;
		gosm_cnt = 0;
		for (int i = 0; i < cnt; i++)
		{
			int x = g.front().first;
			int y = g.front().second;

			g.pop();

			if (x > 0)
				func_gosm(x - 1, y, t[x][y]);
			if (x < r - 1)
				func_gosm(x + 1, y, t[x][y]);
			if (y > 0)
				func_gosm(x, y - 1, t[x][y]);
			if (y < c - 1)
				func_gosm(x, y + 1, t[x][y]);
			
		}
		//show();
	}
	return t[dest.first][dest.second];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	string m_str;
	vector<bool> v_w;
	vector<bool> v_g;

	for (int i = 0; i < r; i++)
	{
		cin >> m_str;
		m.push_back(m_str);
		for (int j = 0; j < c; j++)
		{
			if (m_str[j] == 'D')
			{
				dest.first = i;
				dest.second = j;
				v_w.push_back(0);
				v_g.push_back(0);
			}
			else if (m_str[j] == '*')
			{
				w.push(make_pair(i, j));
				water_cnt++;
				v_w.push_back(1);
				v_g.push_back(0);
			}
			else if (m_str[j] == 'S')
			{
				g.push(make_pair(i, j));
				v_w.push_back(0);
				v_g.push_back(0);
				gosm.first = i;
				gosm.second = j;
			}
			else {
				v_w.push_back(0);
				v_g.push_back(0);
			}
		}
		visit_water.push_back(v_w);
		visit_gosm.push_back(v_g);
	}
	visit_gosm[gosm.first][gosm.second] = 1;
	int ans = bfs();
	if (ans == 0)
		cout << "KAKTUS\n";
	else
		cout << ans << '\n';
	
	return 0;
}