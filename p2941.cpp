#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string t;
	cin >> t;

	int sum = 0;

	for (int i = 0; i < t.length(); i++)
	{
		if (i != t.length() - 1)
		{
			if (t[i] == 'c')
			{
				if (t[i + 1] == '=' || t[i + 1] == '-')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else if (t[i] == 'd')
			{
				if (i != t.length() - 2 && t[i + 1] == 'z' && t[i + 2] == '=')
				{
					sum++;
					i++;
					i++;
				}
				else if (t[i + 1] == '-')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else if (t[i] == 'l')
			{
				if (t[i + 1] == 'j')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else if (t[i] == 'n')
			{
				if (t[i + 1] == 'j')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else if (t[i] == 's')
			{
				if (t[i + 1] == '=')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else if (t[i] == 'z')
			{
				if (t[i + 1] == '=')
				{
					sum++;
					i++;
				}
				else
					sum++;
			}
			else
				sum++;
		}
		else
			sum++;
	}
	cout << sum << endl;

	return 0;
}