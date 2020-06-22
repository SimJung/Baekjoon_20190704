#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, crit, sumint = 0, subjects;
	cout << fixed << setprecision(1);
	cin >> t;

	double grade, sumdouble = 0;

	for (int i = 0; i < t; i++) {
		cin >> subjects;
		sumint = 0;
		sumdouble = 0;
		for (int j = 0; j < subjects; j++) {
			cin >> crit >> grade;
			sumint += crit;
			sumdouble += grade * crit;
		}
		cout << sumint << ' ' << sumdouble / (double)sumint << '\n';
	}
	return 0;
}