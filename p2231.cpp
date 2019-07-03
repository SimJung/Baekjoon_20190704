#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num_s;
	int t, sum;
	cin >> t;
	bool chk = true;
	for (int i = 1; i <= 1000000; i++)
	{
		sum = 0;
		num_s = to_string(i);
		sum += i;
		for (int j = 0; j < num_s.size(); j++)
		{
			sum += num_s[j] - '0';
		}
		if (sum == t)
		{
			sum = i;
			chk = false;
			break;
		}
		if (i > t)
			break;
	}
	if (chk)
		cout << 0 << '\n';
	else
		cout << sum << '\n';
	return 0;
}