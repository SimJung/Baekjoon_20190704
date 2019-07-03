#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159265359

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed << setprecision(6);

	double t;
	cin >> t;

	cout << PI * t * t << '\n'<<t*t*2<<'\n';

	return 0;
}