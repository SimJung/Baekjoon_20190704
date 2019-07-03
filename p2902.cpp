#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string l;
	cin >> l;
	cout << l[0];
	for (int i = 1; i < l.length(); i++)
	{
		if (l[i] == 45)
			cout << l[i + 1];
	}
	cout << '\n';

	return 0;
}