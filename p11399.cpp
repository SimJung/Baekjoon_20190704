#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, sum=0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + t);

	for (int i = 0; i < t; i++)
	{
		sum += arr[i] * (t - i);
	}
	cout << sum << '\n';

	return 0;
}