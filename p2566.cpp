#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, maxx=0, c, l;
	
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> t;
			if (maxx < t)
			{
				maxx = t;
				c = i;
				l = j;
			}
		}
	}
	cout << maxx << '\n' << c << ' ' << l << '\n';
	return 0;
}