#include <iostream>
using namespace std;

int arr[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, sum=0;
	cin >> n>>k;

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	for (int i = 0; i < k; i++)
	{
		if (arr[i] % 2)
			arr[i]++;

		arr[i] /= 2;

		sum += arr[i];
	}

	if (sum >= n)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}