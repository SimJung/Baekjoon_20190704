#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, idx = 6, i=6659, chk=0;
	cin >> t;

	if (t <= 6)
	{
		cout << t - 1 << "666\n";
		return 0;
	}
	while (1)
	{
		chk = 0;
		i++;
		string num = to_string(i);
		for (int j = 0; j < num.length(); j++)
		{
			if (num[j] == '6')
				chk++;
			else
				chk = 0;
			if (chk == 3)
				break;
		}
		if (chk == 3)
			idx++;
		if (idx == t)
			break;
	}
	
	cout << i << '\n';
	return 0;
}