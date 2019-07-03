#include <iostream>
using namespace std;

int arr[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, sum=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sum += k / arr[i];
		k %= arr[i];
	}
	cout << sum << '\n';
	return 0;
}