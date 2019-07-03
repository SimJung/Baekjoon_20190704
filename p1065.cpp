#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum=0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i < 100)
			sum++;

		else if (i < 1000)
		{
			int d1 = (i / 100) - (i/10)%10;
			int d2 = ((i / 10) % 10) - (i % 10);

			if (d1 == d2)
				sum++;
		}
	}

	cout << sum << '\n';

	return 0;
}