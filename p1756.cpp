#include <iostream>
using namespace std;

int oven[300001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, n,pizza, now_idx, min_val = 1000000001;
	cin >> d >> n;
	for (int i = 1; i <= d; i++) {
		cin >> oven[i];
		if (oven[i] > min_val) {
			oven[i] = min_val;
		}
		else if (oven[i] < min_val) {
			min_val = oven[i];
		}
	}

	now_idx = d;
	for (int i = 1; i <= n; i++) {
		cin >> pizza;
		while (pizza > oven[now_idx] && now_idx > 0) {
			now_idx--;
		}

		if (now_idx > 0 && i != n)
			now_idx--;
		else if (now_idx == 0)
			break;
	}
	cout << now_idx << '\n';
	return 0;
}