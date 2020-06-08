#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a, b, c;
	cin >> t;

	while (t--)
	{
		cin >> a >> b >> c;
		if (a > b - c) {
			cout << "do not advertise\n";
		}
		else if (a < b - c) {
			cout << "advertise\n";
		}
		else {
			cout << "does not matter\n";
		}
	}
	return 0;
}