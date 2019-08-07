#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int n;
vector<int> result[1001];

//건설에 걸리는 시간
int time[1001];

vector<int> v[1001];
int id[1001] = { 0, };

void topology()
{
	queue<int> temp;
	int nowl = 0;
	for (int i = 1; i <= n; i++)
	{
		if (id[i] == 0)
			temp.push(i);
	}

	for(int i=1; i<=n; i++)
	{
		int num = temp.front();
		temp.pop();
		result[nowl].push_back(num);

		num = temp.front();
		if(num)

		for (int j = 0; j < v[num].size(); j++)
		{
			if (--id[v[num][j]] == 0)
			{
				temp.push(v[num][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int k, x, y;
		cin >> n >> k;
		for (int i = 0; i <= n; i++)
		{
			v[i].clear();
			id[i] = 0;
		}
		
		for (int i = 1; i <= n; i++)
		{
			cin >> time[i];
		}
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			v[x].push_back(y);
			id[y]++;
		}
		topology();
		for (int i = 1; i <= n; i++)
		{
			cout << result[i] << '\n';
		}
	}
	return 0;
}