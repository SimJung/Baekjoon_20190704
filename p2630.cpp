#include <iostream>
using namespace std;

bool arr[129][129];
int blue_squares = 0, white_squares = 0;

void recur(int start_i, int start_j, int n) {
	bool clr = arr[start_i][start_j], isOne = true;
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
		if (clr)
			blue_squares++;
		else
			white_squares++;
	}
	else {
		recur(start_i, start_j, n / 2);
		recur(start_i + n/2, start_j, n / 2);
		recur(start_i, start_j + n/2, n / 2);
		recur(start_i + n/2, start_j + n/2, n / 2);
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
	cout << white_squares << '\n' << blue_squares << '\n';

	return 0;
}