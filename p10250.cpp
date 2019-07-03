#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, h, w, n;
	cin >> t;

	while (t--)
	{
		int ans = 0;
		cin >> h >> w >> n;

		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				ans++;
				if (ans == n)
				{
					cout << j;
					if (i <= 9)
						cout << '0' << i;
					else
						cout << i;
					cout << '\n';
					break;
				}
			}
			if (ans == n)
				break;
		}
	}

	return 0;
}