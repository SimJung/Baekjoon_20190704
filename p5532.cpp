#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, a, b, c, d, now = 1;
	cin >> l >> a >> b >> c >> d;

	while (true) {
		a -= c;
		b -= d;

		if (a <= 0 && b <= 0)
			break;

		now++;
	}

	cout << l - now << '\n';
	return 0;
}