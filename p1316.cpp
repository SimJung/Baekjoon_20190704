#include <iostream>
#include <string>
using namespace std;

bool arr[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, sum = 0;
	cin >> t;
	string ss;

	while (t--)
	{
		for (int i = 0; i < 26; i++)
			arr[i] = 0;

		cin >> ss;

		if (ss.length() == 1)
		{
			sum++;
		}
		else {
			sum++;
			for (int i = 0; i < ss.length(); i++)
			{
				if (i != ss.length() - 1)
				{
					if (ss[i] != ss[i + 1])
					{
						if (arr[ss[i] - 'a'])
						{
							sum--;
							break;
						}else
							arr[ss[i] - 'a'] = 1;
					}
				}
				else
				{
					if (arr[ss[i] - 'a'])
					{
						sum--;
						break;
					}
					else
						arr[ss[i] - 'a'] = 1;
				}
			}
		}
	}

	cout << sum << '\n';

	return 0;
}