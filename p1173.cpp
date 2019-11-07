#include <iostream>
using namespace std;

int main()
{

	int n, m1, m2, t, r, ex=0, hu =0;
	cin >> n>>m1>>m2>>t>>r;
	
	if (m2 - m1 < t)
	{
		cout << "-1" << '\n';
		return 0;
	}

	if (m2 - m1 < r)
	{
		cout << "-1" << '\n';
		return 0;
	}
	while (ex != n)
	{
		if (m1 == m2 || m2 - m1 < t)
		{
			hu++;
			m1 -= r;
		}
		else
		{
			ex++;
			m1 += t;
		}
	}
	cout << ex + hu << '\n';
	return 0;
}