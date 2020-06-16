#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	char c;

	cin >> a >> c >> b;

		if (c == '+') {
			if (a.length() > b.length()) {
				a.replace(a.begin() + (a.length() - b.length()), a.end(), b);
				cout << a << '\n';
			}
			else if (a.length() < b.length()) {
				b.replace(b.begin() + (b.length() - a.length()), b.end(), a);
				cout << b << '\n';
			}
			else {
				a[0] = '2';
				cout << a << '\n';
			}
		}
		else {
			for (int i = 0; i < b.length() - 1; i++) {
				a.push_back('0');
			}
			cout << a << '\n';
		}
	
	return 0;
}