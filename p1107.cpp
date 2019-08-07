#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// True is broken
bool btn[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num = "";
	int t, len=0, mal, b, minn = 1000001;
	bool chk = true;
	cin >> t>>mal;
	for (int i = 0; i < mal; i++)
	{
		cin >> b;
		btn[b] = 1;
	}
	minn = abs(t - 100);

	for (int i = 0; i < 1000001; i++)
	{
		chk = true;
		num = to_string(i);
		len = num.length();
		for (int j = 0; j < num.length(); j++)
		{
			if (btn[num[j] - '0'])
			{
				chk = false;
				break;
			}
		}
		if (!chk)
			continue;
		if (minn > abs(t - i) + len)
		{
			minn = abs(t - i)+len;
		}
	}
	cout << minn << '\n';
	return 0;
}