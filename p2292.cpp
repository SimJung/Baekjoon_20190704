#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, r = 6, room = 1, process = 1;
	cin >> t;

	while (room < t)
	{
		process++;
		room += r;
		r += 6;
	}
	cout << process << '\n';

	return 0;
}