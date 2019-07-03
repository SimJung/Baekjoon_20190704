#include <iostream>
#include <cmath>
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
		long long int x, y, dist, top, middle, topm1, val;
		cin >> x >> y;
		dist = y - x;
		topm1 = sqrt(dist);
		top = ceil(sqrt(dist));
		middle = top * top - top;
		if (dist == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		if (dist == topm1 * topm1)
		{
			val = topm1 * 2 - 1;
		}
		else if (dist <= middle)
			val = topm1 * 2;
		else if (dist < top*top)
			val = top * 2 - 1;

		cout << val << '\n';
	}

	return 0;
}