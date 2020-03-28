#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, hamburger = 2001, drink = 2001;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		if (hamburger > num)
			hamburger = num;
	}

	for (int i = 0; i < 2; i++) {
		cin >> num;
		if (drink > num)
			drink = num;
	}

	cout << hamburger + drink - 50 << '\n';

	return 0;
}