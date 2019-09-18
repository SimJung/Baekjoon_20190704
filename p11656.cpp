#include <iostream>
#include <string>
using namespace std;

string a;
string arr[1001];

void strsort()
{
	string temp;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = i; j < a.length(); j++)
		{
			bool chk = 0, same = 1;
			for (int k = 0; k < arr[j].length(); k++)
			{
				if (arr[i][k] > arr[j][k])
				{
					chk = 1;
					same = 0;
					break;
				}
				else if (arr[i][k] < arr[j][k])
				{
					same = 0;
					break;
				}
			}
			if (same)
			{
				if (arr[i].length() > arr[j].length())
				{
					chk = 1;
				}
			}

			if (chk)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;

	for (int i = 0; i < a.length(); i++)
	{
		for (int j = i; j < a.length(); j++)
		{
			arr[i].push_back(a[j]);
		}
	}
	strsort();
	for (int i = 0; i < a.length(); i++)
		cout << arr[i] << '\n';

	return 0;
}