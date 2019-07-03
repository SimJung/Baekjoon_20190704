#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 0, b, num;
	for (int i = 1; i <= 9; i++)
	{
		cin >> num;
		if (a < num)
		{
			a = num;
			b = i;
		}
	}
	cout << a << '\n' << b << '\n';
	return 0;
}