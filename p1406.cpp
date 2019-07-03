#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s_left;
stack<char> s_right;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string text, res="";
	cin >> text;

	int t, pos;
	cin >> t;

	char c, temp;

	for (int i = 0; i < text.length(); i++)
	{
		s_left.push(text[i]);
	}

	while (t--)
	{
		cin >> c;

		switch (c)
		{
		case 'L':
			if (!s_left.empty())
			{
				temp = s_left.top();
				s_left.pop();
				s_right.push(temp);
			}
			break;

		case 'D':
			if (!s_right.empty())
			{
				temp = s_right.top();
				s_right.pop();
				s_left.push(temp);
			}
			break;

		case 'B':
			if (!s_left.empty())
			{
				s_left.pop();
			}
			break;

		case 'P':
			char new_char;
			cin >> new_char;

			s_left.push(new_char);
			break;
		}
	}
	
	int lsize = s_left.size(), rsize = s_right.size();
	for (int i = 0; i < lsize; i++)
	{
		res.push_back(s_left.top());
		s_left.pop();
	}

	for (int i = res.length() - 1; i >= 0; i--)
	{
		cout << res[i];
	}

	for (int i = 0; i < rsize; i++)
	{
		cout << s_right.top();
		s_right.pop();
	}
	cout << '\n';

	return 0;
}

