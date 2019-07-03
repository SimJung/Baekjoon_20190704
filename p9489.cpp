#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	if (t <= 100)
	{
		if (t >= 90)
			cout << "A\n";
		else if (t >= 80)
			cout << "B\n";
		else if (t >= 70)
			cout << "C\n";
		else if (t >= 60)
			cout << "D\n";
		else
			cout << "F\n";
	}
	else
		cout << "F\n";
	

	return 0;
}