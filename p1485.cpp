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
		int n = 0, nn=0, pos = 0;
		long long arr[6] = { 0, };
		for (int i = 0; i < 4; i++)
		{
			cin >> num[i][0] >> num[i][1];
		}

		long long dist = (num[1][0] - num[0][0])* (num[1][0] - num[0][0]) + (num[1][1] - num[0][1]) * (num[1][1] - num[0][1]);
		long long crs;
		for (int i = 0; i < 3; i++)
		{
			for (int j = i+1; j < 4; j++)
			{
				long long distt = (num[j][0] - num[i][0]) * (num[j][0] - num[i][0]) + (num[j][1] - num[i][1]) * (num[j][1] - num[i][1]);
				arr[pos] = distt;
				if (dist > distt)
				{
					crs = dist;
					dist = distt;
				}
				if (distt > dist)
					crs = distt;
					

				pos++;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (arr[i] == dist)
				n++;
			else if (arr[i] == crs)
				nn++;
		}
		if (n >= 4 && nn >= 2)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}
	return 0;
}