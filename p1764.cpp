#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> f;
set<string> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string st;
	
	for (int i = 0; i < n; i++)
	{
		cin >> st;
		f.insert(st);
	}
	set<string>::iterator iter;
	for (int i = 0; i < m; i++)
	{
		cin >> st;
		iter = f.find(st);
		if (iter != f.end())
			ans.insert(st);
	}
	cout << ans.size() << '\n';
	for (set<string>::iterator i = ans.begin(); i != ans.end(); i++)
		cout << *i << '\n';
	return 0;
}