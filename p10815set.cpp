#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		s.insert(n);
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (s.find(n) != s.end())
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
	cout << '\n';
	return 0;
}