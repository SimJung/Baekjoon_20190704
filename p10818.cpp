#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, maxx = -1000000, minn = 1000000, num;
	cin >> t;

	while (t--)
	{
		cin >> num;
		maxx = (num > maxx) ? num : maxx;
		minn = (num < minn) ? num : minn;
	}
	cout << minn << ' ' << maxx << '\n';
	return 0;
}