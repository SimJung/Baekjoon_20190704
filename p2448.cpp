#include <iostream>
using namespace std;

int t;
void first(int n, int b)
{
	for (int j = 0; j < b-1; j++)
		cout << ' ';
	cout << '*';
	for (int j = 0; j < t - b; j++)
		cout << ' ';
}
void draw(int n)
{
	if (n >= 3)
	{
		int k = n / 3;
		/*
		for (int i = 10; i >= 0; i--)
		{
			if ((n / 3) % int(pow(2.0, i)) == 0)
			{
				k = i;
				break;
			}
		}
		*/

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	draw(t);
	return 0;
}