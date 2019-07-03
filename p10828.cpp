#include <iostream>
#include <string>
using namespace std;

int st[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, pos=0, num;
	string comd;
	cin >> t;

	while (t--)
	{
		cin >> comd;

		if (comd == "push")
		{
			cin >> num;
			pos++;
			st[pos - 1] = num;
		}
		else if (comd == "pop")
		{
			if (pos >= 1)
			{
				cout << st[pos - 1] << '\n';
				pos--;
			}
			else
				cout << "-1\n";
		}
		else if (comd == "top")
		{
			if (pos >= 1)
				cout << st[pos - 1] << '\n';
			else
				cout << "-1\n";
		}
		else if (comd == "size")
		{
			cout << pos << '\n';
		}
		else if (comd == "empty")
		{
			if (pos == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}