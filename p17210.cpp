#include <iostream>
using namespace std;

unsigned int n, cn=2;
bool chk;
int d, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>chk;
	if (n > 5)
	{
		cout << "Love is open door\n";
		return 0;
	}

	d = chk ? 0 : 1;
	t = d ? 0 : 1;

	while (cn <= n)
	{
		if (!(cn % 2))
			cout << d << '\n';
		else
			cout << t << '\n';
		cn++;
	}

	return 0;
}