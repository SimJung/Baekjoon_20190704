#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> s;
	stack<pair<int,int>> num;
	string bricks;
	cin >> bricks;

	int nowval = 0, depth = -1;
	for (int i = 0; i < bricks.length(); i++) {
		if (bricks[i] == '[' || bricks[i] == '(') {
			s.push(bricks[i]);
			depth++;
		}
		else if (bricks[i] == ']' || bricks[i] == ')') {
			if (i == 0) {
				cout << 0 << endl;
				return 0;
			}
			if (s.empty())
			{
				cout << 0 << endl;
				return 0;
			}
			if (bricks[i] == ']' && s.top() != '[') {
				cout << 0 << endl;
				return 0;
			}
			else if (bricks[i] == ')' && s.top() != '(') {
				cout << 0 << endl;
				return 0;
			}

			char c = s.top();
			s.pop();

			pair<int, int> temp = make_pair(3, depth);

			if (c == '(')
				temp.first = 2;

			num.push(temp);
			depth--;

			while (num.size() > 1)
			{
				temp = num.top();
				num.pop();
				if (temp.second < num.top().second)
				{
					temp.first *= num.top().first;
					num.pop();
					num.push(temp);
				}else if (temp.second == num.top().second)
				{
					temp.first += num.top().first;
					num.pop();
					num.push(temp);
				}
				else
				{
					num.push(temp);
					break;
				}
			}

			//cout << num.top().first << ' ' << num.top().second << endl;
		}
	}
	if (s.empty())
		cout << num.top().first << endl;
	else
		cout << 0 << endl;
	return 0;
}