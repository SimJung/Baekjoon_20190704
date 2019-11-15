#include <iostream>
#include <queue>
using namespace std;
#define PI pair<int, int>

bool m[10][10];
PI p[10][10];
int c[] = { 5, 5, 5 ,5, 5 };
int answer = 0;
void showPI() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << '(' << p[i][j].first << ',' << p[i][j].second << ") ";
		}
		cout << '\n';
	}
}

void setVal(int i, int j) {
	PI temp(0, 0);
	for (int a = i; a >= 0; a--) {
		if (m[a][j])
			temp.first++;
		else
			break;
	}

	for (int a = j; a >= 0; a--) {
		if (m[i][a])
			temp.second++;
		else
			break;
	}

	p[i][j] = temp;
}

void setPaper(int i, int j, int k) {
	bool chk = true;
	if (m[i][j]) {
		if (i + k < 10 && j + k < 10) {
			for (int x = 1; x <= k; x++) {
				if (!(p[i + x][j + x].first >= x + 1 && p[i + x][j + x].second >= x + 1)) {
					chk = false;
					break;
				}
			}
			if (chk && c[k]) {
				c[k]--;
				answer++;
				for (int x = i; x <= i + k; x++) {
					for (int y = j; y <= j + k; y++) {
						m[x][y] = 0;
						setVal(x, y);
					}
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

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> m[i][j];
			setVal(i, j);
		}
	}


	for (int k = 4; k >= 0; k--) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				setPaper(i, j, k);
			}
		}
		/*for (int i = 0; i < 5; i++)
			cout << i + 1 << " : " << c[i] << '\n';
		showPI();*/
	}
	

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (m[i][j]) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << answer << '\n';
	return 0;
}