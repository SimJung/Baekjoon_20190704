#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, sum=0;
	cin >> t;
	t++;

	while (t--)
	{
		sum += t;
	}

	cout << sum << '\n';

	return 0;
}