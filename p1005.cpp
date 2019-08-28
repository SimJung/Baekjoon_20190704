#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int n;
int totaltime;
vector<int> result[1001];

//연결 여부 배열
bool chkarr[1001];


//건설에 걸리는 시간
int time[1001];

vector<int> v[1001];
int id[1001] = { 0, };

int topology(int w)
{
	queue<int> temp;
	int nowl = 0;
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (id[i] == 0)
		{
			temp.push(i);
		}
			
	}

	

	for(int i=1; i<=n; i++)
	{
		int num = temp.front();
		temp.pop();
		result[nowl].push_back(num);

		if (maxx < time[num])
			maxx = time[num];

		bool chk = 1;

		for (int j = 0; j < v[num].size(); j++)
		{
			if (--id[v[num][j]] == 0)
			{
				temp.push(v[num][j]);
				if (chk && temp.front() == v[num][j])
				{
					nowl++;
					chk = 0;
					totaltime += maxx;
					maxx = 0;
				}
			}
		}

		if (num == w)
			return nowl;
	}
	return nowl;
}

void connect(int a)
{
	// w값을 받아 입력 받을 때 바로바로 체크해 주는 게 나을까???
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
		totaltime = 0;
		int k, x, y, w;
		cin >> n >> k;
		for (int i = 0; i <= n; i++)
		{
			v[i].clear();
			result[i].clear();
			id[i] = 0;
			chkarr[i] = 0;
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
		cin >> w;

		int h = topology(w);
		for (int i = 0; i < h; i++)
		{
			cout << i << '\n';
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << totaltime + time[w] << '\n';
	}
	return 0;
}