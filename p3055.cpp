#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
//
//int t[51][51];
//
//vector<string> m;
//vector<vector<bool>> visit_water;
//vector<vector<bool>> visit_gosm;
//int r, c, water_cnt, gosm_cnt=1;
//pair<int, int> dest;
//pair<int, int> gosm;
//queue<pair<int, int>> g;
//queue<pair<int, int>> w;
//
//void show()
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cout << m[i][j];
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cout << t[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << "\n\n";
//}
//
//void func_water(int x, int y)
//{
//	if ((m[x][y] == '.' || m[x][y] == 'S') && !visit_water[x][y])
//	{
//		visit_water[x][y] = 1;
//		m[x][y] = '*';
//		w.push(make_pair(x, y));
//		water_cnt++;
//	}
//}
//
//void func_gosm(int x, int y, int tt)
//{
//	if ((m[x][y] == '.' || m[x][y] == 'D') && (!visit_gosm[x][y] && !visit_water[x][y]))
//	{
//
//		visit_gosm[x][y] = 1;
//		m[x][y] = 'S';
//		t[x][y] = tt+1;
//		gosm_cnt++;
//		g.push(make_pair(x, y));
//	}
//}
//
//int bfs()
//{
//	while (!g.empty())
//	{
//		int cnt = water_cnt;
//		water_cnt = 0;
//		for (int i = 0; i < cnt; i++)
//		{
//			int x1 = w.front().first;
//			int y1 = w.front().second;
//
//			w.pop();
//
//			if (x1 > 0)
//				func_water(x1 - 1, y1);
//			if (x1 < r-1)
//				func_water(x1 + 1, y1);
//			if (y1 > 0)
//				func_water(x1, y1 - 1);
//			if (y1 < c - 1)
//				func_water(x1, y1 + 1);
//		}
//		
//		cnt = gosm_cnt;
//		gosm_cnt = 0;
//		for (int i = 0; i < cnt; i++)
//		{
//			int x = g.front().first;
//			int y = g.front().second;
//
//			g.pop();
//
//			if (x > 0)
//				func_gosm(x - 1, y, t[x][y]);
//			if (x < r - 1)
//				func_gosm(x + 1, y, t[x][y]);
//			if (y > 0)
//				func_gosm(x, y - 1, t[x][y]);
//			if (y < c - 1)
//				func_gosm(x, y + 1, t[x][y]);
//			
//		}
//		//show();
//	}
//	return t[dest.first][dest.second];
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> r >> c;
//	string m_str;
//	vector<bool> v_w;
//	vector<bool> v_g;
//
//	for (int i = 0; i < r; i++)
//	{
//		cin >> m_str;
//		m.push_back(m_str);
//		for (int j = 0; j < c; j++)
//		{
//			if (m_str[j] == 'D')
//			{
//				dest.first = i;
//				dest.second = j;
//				v_w.push_back(0);
//				v_g.push_back(0);
//			}
//			else if (m_str[j] == '*')
//			{
//				w.push(make_pair(i, j));
//				water_cnt++;
//				v_w.push_back(1);
//				v_g.push_back(0);
//			}
//			else if (m_str[j] == 'S')
//			{
//				g.push(make_pair(i, j));
//				v_w.push_back(0);
//				v_g.push_back(0);
//				gosm.first = i;
//				gosm.second = j;
//			}
//			else {
//				v_w.push_back(0);
//				v_g.push_back(0);
//			}
//		}
//		visit_water.push_back(v_w);
//		visit_gosm.push_back(v_g);
//	}
//	visit_gosm[gosm.first][gosm.second] = 1;
//	int ans = bfs();
//	if (ans == 0)
//		cout << "KAKTUS\n";
//	else
//		cout << ans << '\n';
//	
//	return 0;
//}

int r, c, gosm_cnt = 1, water_cnt;
string m[51];
bool visit[51][51];
int t[51][51];
queue<pair<int, int>> gosm;
queue<pair<int, int>> water;
pair<int, int> dest;
pair<int, int> timeVal;

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
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\n\n";
}

void func_gosm(int i, int j)
{
	if ((m[i][j] == '.' || m[i][j] == 'D') && !visit[i][j])
	{
		visit[i][j] = 1;
		m[i][j] = 'S';
		gosm_cnt++;
		t[i][j] = t[timeVal.first][timeVal.second] + 1;
		gosm.push(make_pair(i, j));
	}
}

void func_water(int i, int j)
{
	if ((m[i][j] == '.' || m[i][j] == 'S') && !visit[i][j])
	{
		visit[i][j] = 1;
		m[i][j] = '*';
		water_cnt++;
		water.push(make_pair(i, j));
	}
}
int bfs()
{
	while (!gosm.empty())
	{
		int cnt = water_cnt;
		water_cnt = 0;
		for (int k = 0; k < cnt; k++)
		{
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			if (x > 0)
				func_water(x - 1, y);
			if (x < r - 1)
				func_water(x + 1, y);
			if (y > 0)
				func_water(x, y - 1);
			if (y < c - 1)
				func_water(x, y + 1);
		}

		cnt = gosm_cnt;
		gosm_cnt = 0;
		for (int k = 0; k < cnt; k++)
		{
			int x = gosm.front().first;
			int y = gosm.front().second;
			timeVal = gosm.front();
			
			gosm.pop();

			if (x > 0)
				func_gosm(x - 1, y);
			if (x < r - 1)
				func_gosm(x + 1, y);
			if (y > 0)
				func_gosm(x, y - 1);
			if (y < c - 1)
				func_gosm(x, y + 1);
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
	for (int i = 0; i < r; i++)
	{
		cin >> m[i];
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] == '*')
			{
				water.push(make_pair(i, j));
				water_cnt++;
				visit[i][j] = 1;
			}
			else if (m[i][j] == 'S')
			{
				gosm.push(make_pair(i, j));
				visit[i][j] = 1;
			}
			else if (m[i][j] == 'D')
				dest = make_pair(i, j);
			else if (m[i][j] == 'X')
				visit[i][j] = 1;
		}
	}
	int ans = bfs();
	if (ans == 0)
		cout << "KAKTUS\n";
	else
		cout << ans << '\n';
	return 0;
}