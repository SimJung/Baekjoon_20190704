#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, maxx = 0, num, sum=0;
	cin >> t;

	while (t--)
	{
		cin >> num;
		sum += num;
		if (maxx < num)
			maxx = num;
	}

	cout << sum - maxx << '\n';
	return 0;
}