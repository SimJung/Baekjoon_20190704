#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	if (!(t % 400) || (!(t % 4) && (t % 100)))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}