#include <iostream>
using namespace std;

bool getprime(int n)
{
	if (n == 1)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num, val=0;
	cin >> t;

	while (t--)
	{
		cin >> num;
		val += getprime(num);
	}
	cout << val << '\n';
	return 0;
}