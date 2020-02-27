#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	queue<int> q;

	for (int i = 1; i <= t; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';
	return 0;
}