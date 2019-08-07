#include <iostream>
using namespace std;

long long int arr[91];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= t; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[t] << '\n';
	return 0;
}