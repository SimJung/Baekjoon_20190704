#include <iostream>
#include <vector>
using namespace std;
#define pi pair<int, int>

vector<pi> zero_loc;
int arr[10][10];
bool chkEnd = false;

void show() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool h_ok(pi p, int n)
{
	for (int i = 1; i <= 9; i++) {
		if (arr[p.first][i] == n)
			return false;
	}
	return true;
}

bool v_ok(pi p, int n)
{
	for (int i = 1; i <= 9; i++) {
		if (arr[i][p.second] == n)
			return false;
	}
	return true;
}

bool s_ok(pi p, int n)
{
	for (int i = (p.first - 1)/3 * 3 + 1; i <= (p.first - 1)/3 * 3 + 3; i++) {
		for (int j = (p.second - 1)/3 * 3 + 1; j <= (p.second - 1)/3 * 3 + 3; j++) {
			if (arr[i][j] == n)
				return false;
		}
	}
	return true;
}

void sudoku(int n) {
	pi p = zero_loc[n];
	for (int i = 1; i <= 9; i++) {
		if (h_ok(p, i) && v_ok(p, i) && s_ok(p, i)) {
			arr[p.first][p.second] = i;
			if (n + 1 == zero_loc.size()) {
				chkEnd = true;
				return;
			}
			else if (!chkEnd)
				sudoku(n + 1);
		}

		if (chkEnd)
			return;
	}
	arr[p.first][p.second] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				zero_loc.push_back(make_pair(i, j));
		}
	}
	sudoku(0);

	show();

	return 0;
}