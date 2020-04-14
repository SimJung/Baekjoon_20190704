#include <iostream>
#include <string>
using namespace std;
bool arr[65][65];
string ans = "";

void recur(int start_i, int start_j, int n) {
	bool clr = arr[start_i][start_j], isOne = true;
	for (int i = start_i; i < start_i + n; i++) {
		for (int j = start_j; j < start_j + n; j++) {
			if (arr[i][j] != clr) {
				isOne = false;
				break;
			}
		}
		if (!isOne)
			break;
	}

	if (isOne) {
		ans.push_back((int)clr + '0');
	}
	else {
		ans.push_back('(');

		recur(start_i, start_j, n / 2);
		recur(start_i, start_j + n / 2, n / 2);
		recur(start_i + n/2, start_j, n / 2);
		recur(start_i + n/2, start_j + n/2, n / 2);

		ans.push_back(')');
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		for (int j = 0; j < st.length(); j++) {
			arr[i][j] = st[j] - '0';
		}
	}

	recur(0, 0, n);
	cout << ans << '\n';

	return 0;
}