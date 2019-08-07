#include <iostream>
#include <string>
using namespace std;

bool arr[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string cmd;
	cin >> t;

	while (t--)
	{
		int x;
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> x;
			arr[x] = 1;
		}
		else if (cmd == "remove")
		{
			cin >> x;
			arr[x] = 0;
		}
		else if (cmd == "check")
		{
			cin >> x;
			cout << arr[x] << '\n';
		}
		else if (cmd == "toggle")
		{
			cin >> x;
			arr[x] = !arr[x];
		}
		else if (cmd == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 1;
			}
		}
		else if (cmd == "empty")
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 0;
			}
		}
	}
	return 0;
}