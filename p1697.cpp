#include <iostream>
#include <queue>
using namespace std;

int arr[100001];
bool visit[100001];

queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, now;
	cin >> n >> k;

	visit[n] = 1;
	q.push(n);

	if (n == k)
	{
		cout << 0 << '\n';
		return 0;
	}

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		if (now > 0 && !visit[now-1])
		{
			visit[now - 1] = 1;
			arr[now - 1] = arr[now] + 1;
			q.push(now - 1);
		}
		if (now < 100000 && !visit[now + 1])
		{
			visit[now + 1] = 1;
			arr[now + 1] = arr[now] + 1;
			q.push(now + 1);
		}
		if (now <= 50000 && !visit[now * 2])
		{
			visit[now * 2] = 1;
			arr[now*2] = arr[now] + 1;
			q.push(now * 2);
		}

		if (arr[k])
		{
			cout << arr[k] << '\n';
			return 0;
		}
	}
	return 0;
}