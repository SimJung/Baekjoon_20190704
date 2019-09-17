#include <iostream>
using namespace std;

string a[8];
bool isWhite = true;
int ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
		for (int j = 0; j < 8; j++)
		{
			if (isWhite && a[i][j] == 'F')
				ans++;
			isWhite = !isWhite;
		}
		isWhite = !isWhite;
	}
	cout << ans << '\n';
	return 0;
}