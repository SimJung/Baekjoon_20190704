#include <iostream>
using namespace std;

bool getprime(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < (n / 2) + 1; i++)
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

	int n1, n2, pn, sum=0;
	cin >> n1>>n2;

	for (int i = n2; i >= n1; i--)
	{
		if (getprime(i))
		{
			sum += i;
			pn = i;
		}
	}
	if (sum == 0)
		cout << "-1\n";
	else
		cout << sum << '\n' << pn << '\n';
	return 0;
}