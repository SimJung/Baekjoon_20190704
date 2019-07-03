#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int num;
		string a;
		cin >> num;
		cin >> a;

		for (int i = 0; i < a.length(); i++)
		{
			for (int j = 0; j < num; j++)
			{
				cout << a[i];
			}
		}
		cout << '\n';
	}

	return 0;
}