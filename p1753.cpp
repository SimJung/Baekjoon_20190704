#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pi pair<int, int>
#define INF 2100000000

//first: 가중치, second: 도착지
vector<pi> edges[20001];
int dist[20001];
bool visit[20001];
priority_queue<int, vector<int>, less<int>> q;
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
		edges[u].push_back(make_pair(w, v));
	}

	for (int i = 0; i < edges[startP].size(); i++) {
		q.push()
	}
	return 0;
}