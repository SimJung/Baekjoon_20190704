#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> st;
int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, pos=1;
	string ans = "";
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < t; i++)
	{
		if (pos <= arr[i])
		{
			for (; pos <= arr[i]; pos++)
			{
				st.push(pos);
				ans += '+';
			}
		}

		if (pos > arr[i])
		{
			if (st.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			int temp = st.top();
			st.pop();
			ans += '-';

			if (temp != arr[i])
			{
				cout << "NO" << endl;
				return 0;
			}
		}

		if (ans.length() > t * 2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	if (ans.length() < t * 2)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < ans.length(); i++)
			cout << ans[i] << '\n';
	}
		


	return 0;
}