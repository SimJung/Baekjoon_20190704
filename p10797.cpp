#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num, ans = 0;
	cin >> t;

	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (t == num)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}