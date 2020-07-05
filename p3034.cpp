#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, w, h;
	cin >> t >> w >> h;

	double l;
	l = sqrt(w * w + h * h);

	int a;
	while (t--)
	{
		cin >> a;
		if (a <= l) {
			cout << "DA\n";
		}
		else {
			cout << "NE\n";
		}
	}
	return 0;
}