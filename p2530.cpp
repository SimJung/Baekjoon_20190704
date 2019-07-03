#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, m, s, t;
	cin >> h >> m >> s >> t;

	for (int i = 0; i < t; i++)
	{
		s++;
		if (s >= 60)
		{
			m++;
			s -= 60;
		}
		if (m >= 60)
		{
			h++;
			m -= 60;
		}
		if (h >= 24)
		{
			h -= 24;
		}
	}
	cout << h << ' ' << m << ' ' << s << '\n';
	return 0;
}