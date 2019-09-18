#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	cin >> a;
	bool b = 1;
	for (int i = 0; i < a.length()/2; i++)
	{
		if (a[i] != a[a.length() - 1 - i])
		{
			b = 0;
			break;
		}
	}
	cout << b << '\n';
	return 0;
}