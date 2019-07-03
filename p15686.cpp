#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[52][52];
vector<pair<int, int>> v;
bool openchk[2501];
int city_dis, min_city_dis = 25000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n>>m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	}

	for (int x1 = 0; x1 < v.size(); x1++)
	{
		for(int x2 = )
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1)
			{
				int dis = 10000;
				for (int k = 0; k < v.size(); k++)
				{
					if(openchk[k] == 1)
						dis = min(dis, abs(i - v[k].first) + abs(j - v[k].second));
				}
				city_dis += dis;
			}
		}
	}

	return 0;
}