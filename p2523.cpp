#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = t-1; i >=1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}