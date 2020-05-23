#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define pi pair<int, int>
#define ti tuple<int, int, int>
#define INF 2100000000

//first: 가중치, second: 도착지
vector<ti> edges[20001];
int dist[20001];
bool visit[20001];
priority_queue<ti, vector<ti>, greater<ti>> q;
int a, b, startP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> startP;

	for (int i = 1; i <= a; i++) {
		if (i == startP)
			dist[i] = 0;
		else
			dist[i] = INF;
	}

	visit[startP] = 1;

	//u:출발점, v:도착점, w:가중치
	int u, v, w;
	for (int i = 0; i < b; i++) {
		cin >> u >> v >> w;
		edges[u].push_back(make_tuple(w, u, v));
	}

	for (int i = 0; i < edges[startP].size(); i++) {
		q.push(edges[startP][i]);
	}

	while (!q.empty()) {
		ti temp = q.top();
		q.pop();
		visit[get<2>(temp)] = true;
		if (dist[get<1>(temp)] + get<0>(temp) < dist[get<2>(temp)])
			dist[get<2>(temp)] = dist[get<1>(temp)] + get<0>(temp);
		for (int i = 0; i < edges[get<2>(temp)].size(); i++) {
			if (!visit[edges[get<2>(temp)][i].second]) {
				q.push(edges[get<2>(temp)][i]);
			}
		}
	}

	for (int i = 1; i <= a; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
	return 0;
}