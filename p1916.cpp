#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define pi pair<int, int>

priority_queue<int, vector<int>, greater<int>> pq;
int n, m;

int dist[1001];

//n번째 원소 : 출발점, first: 가중치, second: 도착지
vector<pi> bus[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = 1000000001;
	}
	int depart, dest, cost;
	for (int i = 0; i < m; i++) {
		cin >> depart >> dest >> cost;
		bus[depart].push_back(make_pair(cost, dest));
	}

	cin >> depart >> dest;
	dist[depart] = 0;
	pq.push(depart);

	int nextCity;
	while (!pq.empty()) {
		nextCity = pq.top();
		pq.pop();

		for (int i = 0; i < bus[nextCity].size(); i++) {
			if (dist[bus[nextCity][i].second] > dist[nextCity] + bus[nextCity][i].first) {
				dist[bus[nextCity][i].second] = dist[nextCity] + bus[nextCity][i].first;
				pq.push(bus[nextCity][i].second);
			}
		}
	}

	cout << dist[dest] << '\n';
	return 0;
}