#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int t;
	string command;
	cin >> t;

	while (t--)
	{
		cin >> command;

		if (command == "push")
		{
			int n;
			cin >> n;
			q.push(n);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else 
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "size")
			cout << q.size() << '\n';
		else if (command == "empty")
			cout << q.empty() << '\n';
		else if (command == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (command == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}