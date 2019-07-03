#include <iostream>
using namespace std;

char arr[2188][2188];

int star(int n, int x, int y)
{
	if (n == 3)
	{
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j <y + 3; j++)
			{
				if (i == x+1 && j == y+1)
					continue;
				arr[i][j] = '*';
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
					continue;
				

				star(n / 3, x+i*n/3, y + j * n / 3);
			}
		}
	}

	return 0;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	star(t, 1, 1);
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (arr[i][j])
				cout << arr[i][j];
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}