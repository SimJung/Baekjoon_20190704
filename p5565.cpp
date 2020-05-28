#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num;
	cin >> t;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		t -= num;
	}
	cout << t << '\n';
	return 0;
}