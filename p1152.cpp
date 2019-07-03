#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	int t = 1;

	getline(cin, a);

	if (a == " ")
	{
		cout << 0 << '\n';
		return 0;
	}
	else
	{
		for (int i = 1; i < a.length() - 1; i++)
		{
			if (a[i] == ' ')
			{
				if (a[i + 1] != '\n')
					t++;

			}

		}
	}

	

	cout << t << '\n';
	return 0;
}