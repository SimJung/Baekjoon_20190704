#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	int ans = 0, minn = 51;
	cin >> a >> b;
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != b[i])
				ans++;
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		ans = 0;
		for (int j = i; j < a.length() + i; j++)
		{
			if (a[j-i] != b[j])
				ans++;
		}
		if (minn > ans)
			minn = ans;
	}
	cout << minn << '\n';
	return 0;
}