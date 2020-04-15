#include <iostream>
using namespace std;

int arr[2188][2188];
int squares_n1 = 0, squares_0 = 0, squares_1 = 0;

void recur(int start_i, int start_j, int n) {
	int clr = arr[start_i][start_j];
	bool isOne = true;
	for (int i = start_i; i < start_i + n; i++) {
		for (int j = start_j; j < start_j + n; j++) {
			if (clr != arr[i][j]) {
				isOne = false;
				break;
			}
		}
		if (!isOne)
			break;
	}

	if (isOne) {
		if (clr == 1)
			squares_1++;
		else if (clr == 0)
			squares_0++;
		else
			squares_n1++;
	}
	else {
		recur(start_i				, start_j, n / 3);
		recur(start_i + n / 3		, start_j, n / 3);
		recur(start_i + n / 3 *  2	, start_j, n / 3);
		recur(start_i				, start_j + n / 3, n / 3);
		recur(start_i + n / 3		, start_j + n / 3, n / 3);
		recur(start_i + n / 3 * 2	, start_j + n / 3, n / 3);
		recur(start_i				, start_j + n / 3 * 2, n / 3);
		recur(start_i + n / 3		, start_j + n / 3 * 2, n / 3);
		recur(start_i + n / 3 * 2	, start_j + n / 3 * 2, n / 3);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	recur(0, 0, n);
	cout << squares_n1 << '\n' << squares_0 << '\n'<<squares_1<<'\n';

	return 0;
}