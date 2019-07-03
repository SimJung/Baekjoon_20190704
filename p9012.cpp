#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		stack<char> s;
		string strr;
		bool chk = true;
		cin >> strr;

		for (int i = 0; i < strr.length(); i++)
		{
			if (strr[i] == '(')
				s.push('(');
			else if(!s.empty())
				s.pop();
			else
			{
				chk = false;
				break;
			}
		}

		if (chk && s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}