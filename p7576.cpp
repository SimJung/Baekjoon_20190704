#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[1005][1005];	//�湮 üũ
bool chkempty = 1;
int map[1005][1005];	//�ʱ� �Է¹޴� �丶�� ����
int map_data[1005][1005];//�ɸ��� �ð� �Է�
int n, m, sum;
int maxx = -1;
queue<pair<int, int>> q;
int arr_x[] = { 0, 1, 0, -1 };
int arr_y[] = { 1, 0, -1, 0 };

void chkAns()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map_data[i][j] == 100000000)	//10000�̸� �� ���� �丶��
			{
				maxx = -1;
				return;
			}
			else if (map_data[i][j] != 100000001)	//10001�̸� ��
				maxx = max(maxx, map_data[i][j]);
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int px = x + arr_x[i];
			int py = y + arr_y[i];

			if (px >= 0 && px < m && py >= 0 && py < n)
			{
				if (visit[px][py] == 0 && map[px][py] == 0)
				{
					visit[px][py] = 1;
					q.push(make_pair(px, py));
					map_data[px][py] = map_data[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(make_pair(i, j));	//���� �丶�� ť�� �ֱ�
			sum += map[i][j];
		}
	}

	if (sum == n * m)	//ó������ �� �;��� ���
	{
		cout << "0\n";
		return 0;
	}
	else if (sum == n * m*-1)	//���� �� ���� ���
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < m; i++)	//�ð� ��Ÿ���� �迭 �ʱ�ȭ
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
				map_data[i][j] = 100000000;
			else if (map[i][j] == -1)
				map_data[i][j] = 100000001;
			else
				map_data[i][j] = 0;
		}
	}

	bfs();
	chkAns();
	cout << maxx << '\n';

	return 0;
}

