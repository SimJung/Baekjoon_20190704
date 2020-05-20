#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, mid, r=0, l, sum = 0, con;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (r < arr[i])
			r = arr[i];
	}
	cin >> con;

	l = 0;

	while (l <= r) {
		sum = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < t; i++) {
			if (arr[i] <= mid)
				sum += arr[i];
			else
				sum += mid;
		}

		if (sum > con)
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << r << '\n';
	return 0;
}