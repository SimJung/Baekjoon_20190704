#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, sum = 0;
	string s;
	cin >> t;
	cin >> s;
	while (t--)
	{
		sum += s[t] - '0';
	}

	cout << sum << '\n';

	return 0;
}