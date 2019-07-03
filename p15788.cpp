#include <iostream>
using namespace std;

long long int arr[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, y;
	long long int vert=0, crs1=0, crs2=0, v_sum=0, h_sum=0, xy=0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}

	int idx = 0, idy = 0;
	if (x == 0)
		idx = 1;
	if (y == 0)
		idy = 1;

	for (int i = 0; i < t; i++)
		vert += arr[idx][i];

	bool chk = 0;

	for (int i = 0; i < t; i++)
	{
		chk = 0;
		v_sum = 0;
		h_sum = 0;
		for (int j = 0; j < t; j++)
		{
			if (i == x && j == y)
			{
				chk = 1;
				break;
			}
			v_sum += arr[i][j];
		}
		for (int j = 0; j < t; j++)
		{
			if (i == y && j == x)
			{
				chk = 1;
				break;
			}
			h_sum += arr[j][i];
		}
		if (v_sum != vert || h_sum != vert)
		{
			if (chk)
				continue;
			cout << -1 << endl;
			return 0;
		}
		else
		{
			v_sum = 0;
			h_sum = 0;
		}
	}

	for (int i = 0; i < t; i++)
	{
		xy += arr[x][i];
	}

	if (x == y)
	{
		for (int i = 0; i < t; i++)
		{
			crs1 += arr[i][i];
			crs2 += arr[t - 1 - i][i];
		}

		if (crs2 > crs1)
		{
			int temp = crs2;
			crs2 = crs1;
			crs1 = temp;
		}
		if (crs1 != vert && crs2 != xy)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	else {
		for (int i = 0; i < t; i++)
		{
			crs1 += arr[i][i];
			crs2 += arr[t - 1 - i][i];
		}
		if (crs2 > crs1)
		{
			int temp = crs2;
			crs2 = crs1;
			crs1 = temp;
		}
		if (crs1 != vert && crs2 != xy)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	cout << vert - xy << '\n';

	return 0;
}