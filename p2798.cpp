#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, sum = 0;
	cin >> n>>m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] == m)
				{
					sum = arr[i] + arr[j] + arr[k];
					break;
				}
				else if(arr[i] + arr[j] + arr[k] < m)
					sum = max(sum, arr[i] + arr[j] + arr[k]);
			}
			if (sum == m)
				break;
		}
		if (sum == m)
			break;
	}
	cout << sum << '\n';
	return 0;
}