#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, ib;
	string b;
	cin >> a >> b;
	const char *cb = b.c_str();
	
	ib = atoi(cb);

	cout << a * (cb[2]-'0') << '\n';
	cout << a * (cb[1] - '0') << '\n';
	cout << a * (cb[0] - '0') << '\n';
	cout << a * ib << '\n';
	return 0;
}