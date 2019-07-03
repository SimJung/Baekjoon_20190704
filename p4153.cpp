#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x=1, y=1, z=1;
	

	while (1)
	{
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0)
			break;
		if (x > y && x > z)
			swap(x, z);
		if (y > x && y > z)
			swap(y, z);
		if (x*x + y*y == z*z)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}