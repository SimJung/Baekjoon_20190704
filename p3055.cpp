#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> m;
vector<vector<bool>> visit_water;
vector<vector<bool>> visit_gosm;
int r, c;
pair<int, int> gosm;
pair<int, int> water;
pair<int, int> dest;
queue<pair<int, int>> g;
queue<pair<int, int>> w;
int ans;

void func_water(int x, int y)
{
	if ((m[x][y] == '.' || m[x][y] == 'S') && !visit_water[x][y])
	{
		visit_water[x][y] = 1;
		m[x][y] = '*';
		w.push(make_pair(x, y));
	}
}

int bfs()
{

	while (!g.empty())
	{
		if (!w.empty())
		{
			int x = w.front().first;
			int y = w.front().second;

			w.pop();

			if (x > 0)
				func_water(x - 1, y);
			if (x < c - 1)
				func_water(x + 1, y);
			if (y > 0)
				func_water(x, y - 1);
			if (y < r - 1)
				func_water(x, y + 1);
		}
		
	}

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
			}
			if (m_str[j] == '*')
			{
				water.first = i;
				water.second = j;
			}
			if (m_str[j] == 'S')
			{
				gosm.first = i;
				gosm.second = j;
			}
			v_w.push_back(0);
			v_g.push_back(0);
		}
		visit_water.push_back(v_w);
		visit_gosm.push_back(v_g);
	}
	return 0;
}