#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	if (t != 1) {
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				if (j % 2)
					cout << ' ';
				else
					cout << '*';
			}
			cout << '\n';
			for (int j = 0; j < t; j++) {
				if (j % 2)
					cout << '*';
				else
					cout << ' ';
			}
			cout << '\n';
		}
	}
	else
		cout << "*\n";
	
	return 0;
}