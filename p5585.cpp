#include <iostream>
using namespace std;

int coins[] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans = 0;
	cin >> t;

	t = 1000 - t;

	for (int i = 0; i < 6; i++)
	{
		ans += t / coins[i];
		t %= coins[i];
	}
	cout << ans << '\n';

	return 0;
}