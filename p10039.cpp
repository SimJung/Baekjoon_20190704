#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[5], sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		if (arr[i] < 40)
			arr[i] = 40;

		sum += arr[i];
	}

	cout << sum / 5 << '\n';

	return 0;
}