#include <iostream>
using namespace std;

long long int comb(long long int n, long long int r)
{
	if (n == r || r == 0)
		return 1;

	return (comb(n - 1, r - 1))%1000000007 + (comb(n - 1, r))%1000000007;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, m;
	cin >> n>>m;
	cout << comb(n,m) << '\n';


	return 0;
}