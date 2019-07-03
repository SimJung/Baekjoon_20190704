#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n, real;
	cin >> a >> b >> n;

	real = n - a;
	if (real > 0)
		cout << (int)ceil((double)real / (a - b)) + 1 << '\n';
	else
		cout << "1\n";
	return 0;
}