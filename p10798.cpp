#include <iostream>
using namespace std;
string strs[6] = { "", };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		cin >> strs[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 1; j <= 5; j++) {
			if (strs[j].length() > i) {
				cout << strs[j][i];
			}
		}
	}
	cout << '\n';
	return 0;
}