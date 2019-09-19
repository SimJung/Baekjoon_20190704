#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	string dont = "CAMBRIDGE";
	cin >> a;

	int len = a.length();

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < dont.length(); j++)
		{
			if (a[i] == dont[j])
				a[i] = ' ';
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != ' ')
			cout << a[i];
	}
	cout << '\n';
	return 0;
}