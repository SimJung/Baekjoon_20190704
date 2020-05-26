#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans = 0, now = 1;
	cin >> t;

	while (t)
	{
		if (t >= now) {
			t -= now;
			now++;
			ans++;
		}
		else {
			t--;
			now = 2;
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}