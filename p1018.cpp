#include <iostream>
#include <string>
using namespace std;

char arr[51][51], new_arr[51][51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	bool ru_B = true;
	cin >> n >> m;

	string a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = a[j];
		}
	}

	for (int i = 0; i < n - 8; i++)
	{
		for (int j = 0; j < m - 8; j++)
		{
			
			for (int k = j+1; k < j + 8; k++)
			{

			}
			for (int k = i+1; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{

				}
			}
		}
	}

	return 0;
}