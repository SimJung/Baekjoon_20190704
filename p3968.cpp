#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, score=0;
	bool chk = true;
	cin >> t;

	string a;
	while (t--)
	{
		cin >> a;
		for (int i = 0; i < a.size(); i++) {
			if (st.empty() || st.top() != a[i])
				st.push(a[i]);
			else {
				if (!st.empty()) {
					if(st.top() == a[i])

				}
			}
		}

		if (chk)
			score++;
	}
	return 0;
}