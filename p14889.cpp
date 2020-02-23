#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n, team1s, team2s, minn = 2100000000;
int arr[21][21];
vector<int> team1;
vector<int> team2;
bool chkTeam[21];

void backtrack(int idx, int sz) {
	if (sz == n / 2) {
		team1s = 0;
		team2s = 0;
		team1.clear();
		team2.clear();
		for (int i = 1; i <= n; i++) {
			if (chkTeam[i])
				team1.push_back(i);
			else
				team2.push_back(i);
		}

		for (int i = 0; i < (n / 2)-1; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				team1s += arr[team1[i]][team1[j]];
				team1s += arr[team1[j]][team1[i]];
				team2s += arr[team2[i]][team2[j]];
				team2s += arr[team2[j]][team2[i]];
			}
		}
		int sc = abs(team1s - team2s);
		if (sc < minn)
			minn = sc;
	}
	else {
		for (int i = idx; i <= sz + n/2; i++) {
			chkTeam[i] = 1;
			backtrack(i+1, sz + 1);
			chkTeam[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	backtrack(1, 0);
	cout << minn << '\n';
	return 0;
}