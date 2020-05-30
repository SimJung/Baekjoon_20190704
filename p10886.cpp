#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, c=0, nc=0;
	bool chk;
	cin >> t;

	while (t--)
	{
		cin >> chk;
		if (chk)
			c++;
		else
			nc++;
	}
	if (c > nc)
		cout << "Junhee is cute!\n";
	else
		cout << "Junhee is not cute!";
	return 0;
}