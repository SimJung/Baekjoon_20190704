#include <iostream>
using namespace std;

long long int sum, s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int i = 0;
	while (++i) {
		sum += i;
		if (sum > s) {
			cout << i - 1 << '\n';
			return 0;
		}
	}

	return 0;
}