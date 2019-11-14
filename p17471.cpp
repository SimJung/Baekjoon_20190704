#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int n;
int sz;
int p[11];
vector<int> v[11];
int a1[11];
int a2[11];
int submin = 987654321;
bool visit[11];
bool bfsVisit[11];

bool bfs(int a[], int x[], int sz) {
	queue<int> q;
	memset(bfsVisit, 0, 11);
	q.push(a[0]);
	bfsVisit[a[0]] = 1;

	for (int i = 0; i < n - sz; i++) {
		if (x[i]) 
			bfsVisit[x[i]] = 1;
		else
			break;
	}

	while (!q.empty()) {
		int key = q.front();
		q.pop();

		for (int i = 0; i < v[key].size(); i++) {
			if (!bfsVisit[v[key][i]]) {
				bfsVisit[v[key][i]] = 1;
				q.push(v[key][i]);
			}
		}
	}

	for (int i = 0; i < sz; i++) {
		if (!bfsVisit[a[i]])
			return false;
	}
	return true;
}

void func(int push_val, int a1idx) {
	if (a1idx != sz) {
		for (int i = push_val; i <= n; i++) {
			a1[a1idx] = i;
			func(i + 1, a1idx+1);
		}
	}
	else {
		int a2idx = 0;
		for (int i = 0; i <= n; i++) {
			if (a1[i])
				visit[a1[i]] = 1;
			else
				break;
		}

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				a2[a2idx] = i;
				a2idx++;
			}
		}

		if (bfs(a1, a2, sz) && bfs(a2, a1, n - sz)) {
			int p1 = 0, p2 = 0;
			for (int i = 0; i < sz; i++)
				p1 += p[a1[i]];
			for (int i = 0; i < n - sz; i++)
				p2 += p[a2[i]];

			if (submin > abs(p1 - p2))
				submin = abs(p1 - p2);
		}

		memset(visit, 0, 11);
		memset(a2, 0, 11);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++) {
		int num, vertex;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> vertex;
			v[i].push_back(vertex);
		}
	}

	for(int i=1; i<=n/2; i++) {
		sz = i;
		func(1, 0);
	}

	if (submin != 987654321)
		cout << submin << '\n';
	else
		cout << "-1\n";
	return 0;
}