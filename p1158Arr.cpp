#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k=-1;
	cin >> n >> m;

	int* arr = new int[n];
	bool* chkarr = new bool[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
		chkarr[i] = 1;
	}

	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (chkarr[i])
			{
				k++;
			}

		}


	}

	cout << ">\n";

	return 0;
}