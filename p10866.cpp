#include <iostream>
#include <string>
using namespace std;

int arr[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f=10000, b=10000, num;
	cin >> t;

	string c;

	while (t--) {
		cin >> c;
		if (c == "push_front") {
			cin >> num;
			arr[f--] = num;
		}
		else if (c == "push_back") {
			cin >> num;
			arr[++b] = num;
		}
		else if (c == "pop_front") {
			if (f == b)
				cout << "-1\n";
			else
				cout << arr[++f] << '\n';

		}
		else if (c == "pop_back") {
			if (f == b)
				cout << "-1\n";
			else
				cout << arr[b--] << '\n';

		}
		else if (c == "size") {
			cout << b - f << '\n';
		}
		else if (c == "empty") {
			if (f == b)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (c == "front") {
			if (f == b)
				cout << "-1\n";
			else
				cout << arr[f+1] << '\n';
		}
		else if (c == "back") {
			if (f == b)
				cout << "-1\n";
			else
				cout << arr[b] << '\n';
		}
	}
	return 0;
}