#include <iostream>
using namespace std;
int n1, n2;
int arr[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

void print(int idx, int sz) {
	if (sz == n2) {
		for (int i = 1; i <= n2; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = arr[idx - 1]; i <= n1; i++) {
			arr[idx] = i;
			print(idx + 1, sz + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;
	print(1, 0);

	return 0;
}