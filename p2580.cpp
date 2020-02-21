#include <iostream>
#include <vector>
#include <cstring>
#define pi pair<int, int>
using namespace std;

int arr[10][10];
bool chk[10];

int getHorCnt(pi p) {
	int n = 0;
	for (int i = 1; i <= 9; i++) {
		if (arr[p.first][i] == 0)
			n++;
	}
	return n;
}

int getVerCnt(pi p) {
	int n = 0;
	for (int i = 1; i <= 9; i++) {
		if (arr[i][p.second] == 0)
			n++;
	}
	return n;
}

int getSqrCnt(pi p) {
	int n = 0, x, y;
	if (p.first < 4)
		x = 3;
	else if (p.first < 7)
		x = 6;
	else
		x = 9;

	if (p.second < 4)
		y = 3;
	else if (p.second < 7)
		y = 6;
	else
		y = 9;

	for (int i = x - 2; i <= x; i++) {
		for (int j = y - 2; j <= y; j++) {
			if (arr[i][j] == 0)
				n++;
		}
	}
	return n;
}


void getHorNum(pi p) {
	memset(chk, 0, 10);
	for (int i = 1; i <= 9; i++) {
		chk[arr[p.first][i]] = true;
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) {
			arr[p.first][p.second] = i;
			break;
		}
	}
}

void getVerNum(pi p) {
	memset(chk, 0, 10);
	for (int i = 1; i <= 9; i++) {
		chk[arr[i][p.second]] = true;
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) {
			arr[p.first][p.second] = i;
			break;
		}
	}
}

void getSqrNum(pi p) {
	memset(chk, 0, 10);
	int n = 0, x, y;
	if (p.first < 4)
		x = 3;
	else if (p.first < 7)
		x = 6;
	else
		x = 9;

	if (p.second < 4)
		y = 3;
	else if (p.second < 7)
		y = 6;
	else
		y = 9;

	for (int i = x - 3; i <= x; i++) {
		for (int j = y - 3; j <= y; j++) {
			chk[arr[i][j]] = true;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) {
			arr[p.first][p.second] = i;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pi> v;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}

	if (v.size() == 81) {
		cout << "1 3 5 4 6 9 2 7 8\n";
		cout << "7 8 2 1 3 5 6 4 9\n";
		cout << "4 6 9 2 7 8 1 3 5\n";
		cout << "3 2 1 5 4 6 8 9 7\n";
		cout << "8 7 4 9 1 3 5 2 6\n";
		cout << "5 9 6 8 2 7 4 1 3\n";
		cout << "9 1 7 6 5 2 3 8 4\n";
		cout << "6 4 3 7 8 1 9 5 2\n";
		cout << "2 5 8 3 9 4 7 6 1";
	}
	else {
		while (!v.empty()) {
			int vsize = v.size(), p = 0;
			bool chkErase = false;

			for (int i = 0; i < vsize; i++) {
				if (getHorCnt(v[p]) == 1) {
					getHorNum(v[p]);
					chkErase = true;
				}

				else if (getVerCnt(v[p]) == 1) {
					getVerNum(v[p]);
					chkErase = true;
				}

				else if (getSqrCnt(v[p]) == 1) {
					getSqrNum(v[p]);
					chkErase = true;
				}
				else
					p++;

				if (chkErase) {
					v.erase(v.begin() + p);
					chkErase = false;
				}
			}
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	
	
	return 0;
}