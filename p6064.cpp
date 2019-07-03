#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int m, n, x, y, tempx, tempy, smallmn, smallxy;
		bool ans = false;
		cin >> m >> n >> x >> y;

		if (m > n)
		{
			smallmn = n;
			smallxy = y;
		}
		else
		{
			smallmn = m;
			smallxy = x;
		}
		tempx = smallxy;
		tempy = smallxy;

		while (tempx > m)
			tempx -= m;
		while (tempy > n)
			tempy -= n;

		for (int i = smallxy; i <= m*n; i += smallmn)
		{
			if (tempx == x && tempy == y)
			{
				cout << i << '\n';
				ans = true;
				break;
			}
			tempx += smallmn;
			tempy += smallmn;

			while (tempx > m)
				tempx -= m;
			while (tempy > n)
				tempy -= n;

		}
		if (!ans)
			cout << -1 << '\n';
	}
	return 0;
}