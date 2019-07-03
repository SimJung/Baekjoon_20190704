#include <iostream>
using namespace std;

int arr[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	bool emotion = 1;
	cin >> n>>a>>b;
	a--; b--;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == a || j == b)
			{
				if (arr[a][b] < arr[i][j])
				{
					emotion = 0;
					break;
				}
			}
		}
		if (!emotion)
			break;
	}

	cout << (emotion ? "HAPPY\n" : "ANGRY\n");

	return 0;
}