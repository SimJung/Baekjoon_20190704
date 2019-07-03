#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string key;
	cin >> n>>m>>key;

	for (int i = 0; i < m; i++)
	{
		string post;
		cin >> post;
		int chk = 0;
		for (int j = 0; j < post.length(); j++)
		{
			if (post[j] == key[chk])
				chk++;
			if (chk == key.length())
				break;
		}
		if (chk == key.length())
			cout << "true\n";
		else
			cout << "false\n";
	}


	return 0;
}