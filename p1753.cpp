#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pi pair<int, int>
#define INF 2100000000

int dist[20001];
//first: 가중치, second: 도착지
vector<pi> edges[20001];
int vc, e, k, u, v, w;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> vc >> e>>k;
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(w, v));
	}

	for (int i = 1; i <= vc; i++) {
		if (i != k)
			dist[i] = INF;
	}

	pq.push(make_pair(0, k));
	dist[k] = 0;

	while (!pq.empty()) {
		pi now = pq.top();
		pq.pop();
		if (dist[now.second] == now.first) {
			for (auto i : edges[now.second]) {
				if (dist[now.second] + i.first < dist[i.second]) {
					dist[i.second] = dist[now.second] + i.first;
					pq.push(make_pair(i.first + now.first, i.second));
				}
			}
		}
	}

	for (int i = 1; i <= vc; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
	return 0;
}