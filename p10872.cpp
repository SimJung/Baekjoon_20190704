#include <iostream>
using namespace std;

int fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return n * fac(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	cout << fac(t) << '\n';
	return 0;
}