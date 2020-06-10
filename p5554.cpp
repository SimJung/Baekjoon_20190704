#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		sum += a;
	}

	cout << sum / 60 << '\n' << sum % 60 << '\n';
	return 0;
}