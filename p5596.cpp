#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t1, t2, t3, t4;
	int a1, a2, a3, a4;

	cin >> t1 >> t2 >> t3 >> t4;
	cin >> a1 >> a2 >> a3 >> a4;

	if (t1 + t2 + t3 + t4 > a1 + a2 + a3 + a4) {
		cout << t1 + t2 + t3 + t4 << '\n';
	}else
		cout << a1 + a2 + a3 + a4 << '\n';
	return 0;
}