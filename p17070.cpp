#include <iostream>
using namespace std;

int n;
bool arr[17][17];
enum p{hor, ver, crs};
//type 0 : 
int getVal(int x, int y, p type)
{
	if (type == crs)
	{
		if ((x == n || y == n) || (arr[x + 1][y] || arr[x][y + 1] || arr[x + 1][y + 1]))
			return 0;

		else if (x == n - 1 && y == n - 1)
			return 1;

		return getVal(x + 1, y + 1, hor)
			+ getVal(x + 1, y + 1, ver)
			+ getVal(x + 1, y + 1, crs);
	}
	else if (type == hor)
	{
		if (y == n || arr[x][y + 1])
			return 0;

		else if (x == n && y == n - 1)
			return 1;

		return getVal(x, y + 1, hor) + getVal(x, y + 1, crs);
	}
	else if (type == ver)
	{
		if (x == n || arr[x + 1][y])
			return 0;

		else if (x == n - 1 && y == n)
			return 1;

		return getVal(x+1, y, ver) + getVal(x+1, y, crs);
	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	int way = getVal(1, 1, hor);
	cout << way << '\n';
	return 0;
}