#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, sum = 0;
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++){
			cin >> a;
			sum += a;
		}

		switch (sum)
		{
		case 0:
			cout << "D\n";
			break;

		case 3:
			cout << "A\n";
			break;

		case 2:
			cout << "B\n";
			break;

		case 1:
			cout << "C\n";
			break;

		default:
			cout << "E\n";
			break;
		}
	}
	return 0;
}