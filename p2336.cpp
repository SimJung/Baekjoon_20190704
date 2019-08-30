#include <iostream>
using namespace std;

int test[500001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num;
	cin >> t;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cin >> num;
			test[num][i] = j;
		}
	}

	for (int i = 1; i <= t; i++)
	{

	}
	return 0;
}