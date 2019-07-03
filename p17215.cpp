#include <iostream>
#include <string>
using namespace std;

pair<int, int> score[11];
int turn = 1;
char sp[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strr;
	cin >> strr;

	for (int i = 0; i < strr.length(); i++)
	{
		if (strr[i] == 'S')
		{
			if (turn != 10)
			{
				score[turn].first = 10;
				sp[turn] = 'S';
				turn++;
				continue;
			}
		}
		else if (strr[i] == 'P')
		{
			score[turn].second = 10-strr[i-1];
			sp[turn] = 'P';
			turn++;
			continue;
		}
	}
	return 0;
}