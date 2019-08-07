#include <iostream>
#include <string>
using namespace std;

long long int arr[101][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, sum=0;
	cin >> t;
	arr[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}

	for (int i = 2; i <= t; i++)
	{
		arr[i][0] = arr[i - 1][1]%1000000000;
		for (int j = 1; j < 9; j++)
		{
			arr[i][j] = (arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000) % 1000000000;
		}
		arr[i][9] = arr[i - 1][8] % 1000000000;
	}

	for (int i = 0; i < 10; i++)
	{
		sum += arr[t][i];
		sum %= 1000000000;
	}
	cout << sum << '\n';


	/*
	string a;
	bool chk = true;
	int sum = 0;

	for (int i = 1; i < 100000; i++)
	{
		a = to_string(i);
		chk = true;
		for (int j = 1; j < a.length(); j++)
		{
			if (a[j] != a[j - 1] + 1 && a[j] != a[j - 1] - 1)
			{
				chk = false;
				break;
			}
		}
		if (chk)
		{
			sum++;
			cout << a << ' ';
		}
			
		if (i == 9 || i == 99 || i==999 || i==9999 || i==99999)
		{
			cout << '\n';
			cout << a.length() << "자리수의 계단수 개수 : " << sum << '\n';
			sum = 0;
		}
	}*/

	return 0;
}