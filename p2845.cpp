#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, p, n;
	cin >> l>>p;

	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		cout << n - l * p << ' ';
	}
	return 0;
}