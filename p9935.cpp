#include <iostream>
#include <string>
#include <stack>
using namespace std;

string a, b;
stack<char> s1, s2;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a>>b;
	for (int i = 0; i < a.length(); i++)
	{
		s1.push(a[i]);
	}
	
	return 0;
}