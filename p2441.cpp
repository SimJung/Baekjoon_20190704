#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}

		for (int j = i; j < t; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}