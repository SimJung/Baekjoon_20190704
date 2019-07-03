#include <iostream>
using namespace std;

bool arr[246913];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	arr[1] = 1;

	for (int i = 2; i <= 246912; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; j <= 246912 / i; j++)
			{
				arr[i*j] = 1;
			}
		}
	}

	while (t != 0)
	{
		int num = 0;
		for (int i = t+1; i <= t * 2; i++)
		{
			if (!arr[i])
				num++;
		}
		cout << num << '\n';
		cin >> t;
	}

	return 0;
}