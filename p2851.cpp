#include <iostream>
using namespace std;

int arr[10], sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		if (sum + arr[i] <= 100)
			sum += arr[i];
		else {
			if (sum + arr[i] - 100 <= 100 - sum) {
				cout << sum + arr[i] << '\n';
				return 0;
			}
			else {
				cout << sum << '\n';
				return 0;
			}
		}
	}
	cout << sum << '\n';
	return 0;
}