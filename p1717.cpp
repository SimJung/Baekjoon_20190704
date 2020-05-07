#include <iostream>
using namespace std;

int arr[1000001];
int fi(int n) {
	if (arr[n] == n)
		return n;
	else
		return fi(arr[n]);
}

void uni(int a, int b) {
	int a_root = fi(a);
	int b_root = fi(b);
	if (a_root > b_root)
		arr[a_root] = b_root;
	else
		arr[b_root] = a_root;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, c;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a)
			cout << (fi(b) == fi(c) ? "YES\n" : "NO\n");
		else
			uni(b, c);
	}
	return 0;
}