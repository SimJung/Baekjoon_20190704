#include <iostream>
#include <cstring>
using namespace std;

bool earth[51][51];
bool visit[51][51];
int num = 0;
int w, h;

int a1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int a2[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void dfs(int i, int j)
{
	
	if (earth[i][j] && !visit[i][j])
	{
		visit[i][j] = 1;
		for (int k = 0; k < 8; k++)
		{
			if (i + a1[k] >= 0 && i + a1[k] < h && j + a2[k] >= 0 && j + a2[k] < w)
			{
				dfs(i + a1[k], j + a2[k]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	
	while (cin >> w >> h)
	{
		num = 0;
		for (int i = 0; i < h; i++)
			memset(visit[i], 0, w);
		if (w == h && h == 0)
			return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> earth[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (earth[i][j] && !visit[i][j])
				{
					num++;
					dfs(i, j);
				}
			}
		}
		cout << num << '\n';
	}
	return 0;
}