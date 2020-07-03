#include <iostream>
using namespace std;

int arr[8];
int battlePoint;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		for (int i = 0; i < 8; i++) {
			cin >> arr[i];
		}

		int hp, mp, atk, def;
		hp = arr[0] + arr[4];
		mp = arr[1] + arr[5];
		atk = arr[2] + arr[6];
		def = arr[3] + arr[7];

		if (hp < 1)
			hp = 1;

		if (mp < 1)
			mp = 1;
		
		if (atk < 0)
			atk = 0;

		battlePoint = hp + mp * 5 + atk * 2 + def * 2;
		cout << battlePoint<<'\n';
	}
	return 0;
}