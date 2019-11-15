#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PI pair<int, int>

struct cmp {
	bool operator()(PI a, PI b) {
		return a.second > b.second;
	}
};
int v, en, a, b, c, val = 0;
vector<vector<PI>> edge;
priority_queue<PI, vector<PI>, cmp> e;
bool visit[10001];

void prim(int key) {
	visit[key] = 1;
	for (auto u : edge[key]) {
		if (!visit[u.first])
			e.push(u);
	}

	while (!e.empty()) {
		PI f = e.top(); e.pop();
		if(!visit[f.first]){
			val += f.second;
			prim(f.first);
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> en;
	edge.resize(v + 1);
	for (int i = 0; i < en; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a,c });
	}
	prim(a);
	cout << val << '\n';

	return 0;
}