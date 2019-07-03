#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool train[100001][21];
int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cmd, sum=0;
	cin >> n>>m;

	for (int i = 0; i < m; i++)
	{
		int t, x=-1;
		cin >> cmd;

		if (cmd == 1)
		{
			cin >> t >> x;
			train[t][x] = 1;
		}
		else if (cmd == 2)
		{
			cin >> t >> x;
			train[t][x] = 0;
		}
		else if (cmd == 3)
		{
			cin >> t;
			train[t][20] = 0;
			for (int j = 20; j > 1; j--)
			{
				train[t][j] = train[t][j - 1];
			}
			train[t][1] = 0;
		}
		else if (cmd == 4)
		{
			cin >> t;
			train[t][1] = 0;
			for (int j = 1; j < 20; j++)
			{
				train[t][j] = train[t][j+1];
			}
			train[t][20] = 0;
		}

		/*cout << t << "¹ø ±âÂ÷\n";
		for (int j = 1; j < 21; j++)
		{
			cout << setw(3) << j;
		}
		cout << '\n';
		for (int j = 1; j < 21; j++)
		{
			cout << setw(3) << train[t][j];
		}
		cout << '\n';*/
	}

	for (int i = 1; i <= n; i++)
	{
		bool chk = 1;
		for (int j = 1; j < 21; j++)
		{
			arr[i] += train[i][j] * (int)pow(2.0, j-1);
		}

		for (int j = 1; j < i; j++)
		{
			if (arr[j] == arr[i])
			{
				chk = 0;
				break;
			}
		}
		if (chk)
			sum++;

		//cout << arr[i] << '\n';
	}

	cout << sum << '\n';

	return 0;
}