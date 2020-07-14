#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, ans;
void z(int sz, int i, int j, int start, int end) {
	if (sz == 0) {
		if (i == r && c == j)
		{
			cout << start << '\n';
			return;
		}
	}
	else {
		int val = (int)pow(2.0, sz - 1);
		if (r < i + val && c < j + val) {
			z(sz - 1, i, j, start, start + (end - start+1) / 4 - 1);
		}
		else if (r < i + val && c >= j + val) {
			z(sz - 1, i, j + val, start+(end - start + 1) / 4, start + (end - start + 1) / 4 * 2 - 1);
		}
		else if (r >= i + val && c < j + val) {
			z(sz - 1, i + val, j, start + (end - start + 1) / 4 * 2, start + (end - start + 1) / 4 * 3 - 1);
		}
		else {
			z(sz - 1, i + val, j + val, start + (end - start + 1) / 4 * 3, end);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;
	z(n, 0, 0, 0, (int)pow(2.0, n) * (int)pow(2.0, n) - 1);
	return 0;
}