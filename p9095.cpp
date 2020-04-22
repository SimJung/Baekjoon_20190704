#include <iostream>
using namespace std;

int arr[12] = { 0, 1, 2, 4, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 4; i <= 11; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}

	while (t--)
	{
		cin >> n;
		cout << arr[n] << '\n';
	}
	return 0;
}