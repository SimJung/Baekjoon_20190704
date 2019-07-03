#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m, y=1, fe=1, fs=1, fm=1;
	cin >> e >> s >> m;

	while (1)
	{
		if (fe == e && fs == s && fm == m)
			break;

		fe++;	fs++;	fm++;
		if (fe > 15)
			fe = 1;
		if (fs > 28)
			fs = 1;
		if (fm > 19)
			fm = 1;

		y++;

	}
	cout << y << '\n';
	return 0;
}