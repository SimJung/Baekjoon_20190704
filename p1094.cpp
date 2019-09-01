#include <iostream>
using namespace std;

bool arr[65];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans = 1, sum=64, now=64;
	cin >> t;

	while (sum != t)
	{
		now /= 2;

		if (sum - now >= t)
			sum -= now;
		else
			ans++;
	}
	cout << ans << '\n';
	return 0;
}