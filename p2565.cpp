#include <iostream>
using namespace std;

int dp[501];
int pole[501];
int n, a, b, maxx, maxp, res;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		pole[a] = b;
		maxp = (maxp < a) ? a : maxp;
		maxp = (maxp < b) ? b : maxp;

	}

	for (int i = 1; i <= maxp; i++) {
		maxx = 0;
		for (int j = 0; j < i; j++) {
			maxx = (pole[j] < pole[i] && maxx < dp[j] && pole[j] != 0) ? dp[j] : maxx;
		}
		dp[i] = maxx+1;
		res = (res < dp[i]) ? dp[i] : res;
	}
	cout << n - res << '\n';


	return 0;
}