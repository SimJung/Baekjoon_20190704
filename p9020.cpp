#include <iostream>
using namespace std;

bool arr[10001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	arr[1] = 1;
	for (int i = 2; i <= 10000; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; j <= 10000 / i; j++)
			{
				arr[i*j] = 1;
			}
		}
	}

	while (t--)
	{
		int n, val;
		cin >> n;
		for (int i = 2; i <= n / 2; i++)
		{
			if (!arr[i] && !arr[n-i])
				val = i;
		}
		cout << val << ' ' << n - val << '\n';
	}
	return 0;
}