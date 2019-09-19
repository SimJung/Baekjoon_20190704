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
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < (int)'D')
			cout << (char)((int)a[i] + ((int)'X' - (int)'A'));
		else
			cout<< (char)((int)a[i] - 3);
	}
	cout << '\n';
	return 0;
}