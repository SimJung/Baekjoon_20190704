#include <iostream>
using namespace std;

int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a, b;
	cin >> t;

	arr[1] = 1;
	for (int i = 1; i < t; i++) {
		cin >> a >> b;

		if (arr[a] == 0) {
			arr[a] = b;
		}
		else {
			arr[b] = a;
		}
	}

	for (int i = 2; i <= t; i++)
		cout << arr[i] << '\n';
	return 0;
}