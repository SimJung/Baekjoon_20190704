#include <iostream>
using namespace std;

int arr[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>arr[0];
	for (int i = 1; i < 8; i++)
	{
		cin >> arr[i];
		if (arr[0] == 8)
		{
			if (arr[i] == arr[i - 1] - 1)
			{
			}
			else
			{
				cout << "mixed" << endl;
				return 0;
			}
		}
		else if (arr[0] == 1)
		{
			if (arr[i] == arr[i - 1] + 1)
			{
			}
			else
			{
				cout << "mixed" << endl;
				return 0;
			}
		}
		else
		{
			cout << "mixed" << endl;
			return 0;
		}
	}

	if (arr[0] == 1)
		cout << "ascending" << endl;
	else
		cout << "descending" << endl;

	return 0;
}