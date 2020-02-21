#include <iostream>
using namespace std;

int n, max, min;
int arr[12];
int cnt[5];

int calc(int idx, int n, int i) {
	switch (i)
	{
	case 1:
		return n + arr[idx];
	case 2:
		return n - arr[idx];
	case 3:
		return n * arr[idx];
	case 4:
		return n / arr[idx];
	}
}
void backtrack(int idx, int num) {
	if (idx == n) {
		if (num > max)
			max = num;
		if (n < min)
			min = num;
	}
	else {
		for (int i = 1; i <= 4; i++) {
			if (cnt[i]) {
				cnt[i]--;
				int temp = calc(idx, num, i);
				backtrack(idx + 1, temp);
				cnt[i]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= 4; i++) {
		cin >> cnt[i];
	}

	max = 0;
	min = 1000000001;

	backtrack(1, arr[0]);

	cout << max << '\n' << min << '\n';
	return 0;
}