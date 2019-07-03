#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int t, i=-1, c=-1;
	string num_s;
	cin >> t;

	while (++i || 1)
	{
		num_s = to_string(i);

		cout << "i : " << i << "\tc : " << c << '\n';
		bool chk = true;
		for (int j = 1; j < num_s.size(); j++)
		{
			if (num_s[j] >= num_s[j - 1])
			{
				chk = false;
				break;
			}
		}
		if (chk)
			c++;

		if (c == t)
			break;

		if (i > 9876543210)
		{
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << i << '\n';

	return 0;
}