#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c)
	{
		cout << -1 << '\n';
		return 0;
	}

	double d = (double)a / (double)(c - b);
	if ((int)d < d)
		cout << (int)ceil(d) << '\n';
	else
		cout << int(d + 1) << '\n';
	return 0;
}