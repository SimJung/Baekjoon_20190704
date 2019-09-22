#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int num[4][2];
	
	cin >> t;

	while (t--)
	{
		int n = 0;
		long long dist = -1;
		for (int i = 0; i < 4; i++)
		{
			cin >> num[i][0] >> num[i][1];
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = i+1; j < 4; j++)
			{
				long long distt = (num[j][0] - num[i][0]) * (num[j][0] - num[i][0]) + (num[j][1] - num[i][1]) * (num[j][1] - num[i][1]);
				if (dist == -1)
				{
					dist = distt;
				}
				if (distt == dist)
				{
					n++;

				}
			}
		}
		if (n >= 4)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}
	return 0;
}