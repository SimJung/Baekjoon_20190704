#include <iostream>
using namespace std;

int arr[1001], dp[1001], sum, maxx;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i - 1] < arr[j])
			{
				if (dp[i - 1] + 1 > dp[j])
					dp[j] = dp[i - 1] + 1;
			}

			if (maxx < dp[j])
				maxx = dp[j];
		}
	}

	cout << maxx + 1 << '\n';
	return 0;
}