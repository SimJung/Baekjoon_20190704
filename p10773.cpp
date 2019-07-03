#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;

	int t, num, sum=0;
	cin >> t;

	while (t--)
	{
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
	return 0;
}