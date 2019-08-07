#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int t, cnt=0, i=665;
	cin >> t;
	
	while (cnt < t)
	{
		i++;
		s = to_string(i);
		if (s.find("666") != string::npos)
			cnt++;
	}
	cout << i << '\n';

	return 0;
}