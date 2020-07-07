#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a = 1, b = 0, prev_a;
	cin >> t;
	
	while (t--) {
		prev_a = a;
		a = b;
		b += prev_a;
	}
	
	cout << a << ' ' << b << '\n';
	return 0;
}