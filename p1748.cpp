#include <iostream>
using namespace std;

int getlen(int n) {
	int len = 1;
	while (n /= 10)
		len++;

	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, temp = 1;
	long long len = 0;
	cin >> t;

	/*

	브루트포스
	for (int i = 1; i <= t; i++) {
		len += getlen(i);
	}

	*/

	for (int i = 1; i <= t; i*=10) {
		if (i * 10 <= t) {
			len += 9 * i * temp++;
		}
		else {
			len += (t - i + 1)* temp;
		}
	}
	cout << len << '\n';
	return 0;
}