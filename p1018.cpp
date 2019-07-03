#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char arr[51][51], new_arr[51][51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, b_num = 0, w_num = 0, minn = 2500000;
	bool ru_B = true;
	cin >> n >> m;

	string a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = 0; j < m; j++)
			arr[i][j] = a[j];
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			b_num = 0; w_num = 0;
			for (int k = i; k < i+8; k++)
			{
				for (int l = j; l < j+8; l++)
				{
					if ((k % 2 && l % 2) || !(k % 2 || l % 2))
					{
						if (arr[k][l] == 'W')
							b_num++;
						else
							w_num++;
					}
					else
					{
						if (arr[k][l] == 'B')
							b_num++;
						else
							w_num++;
					}
				}
			}
			minn = min(minn, min(b_num, w_num));
		}
	}
	cout << minn << '\n';
	return 0;
}