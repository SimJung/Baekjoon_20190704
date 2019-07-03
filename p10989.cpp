#include <iostream>
#include <cstdlib>
using namespace std;

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num, maxx=0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> num;

		arr[num]++;
		if (num > maxx)
			maxx = num;
	}

	for (int i = 0; i <= maxx; i++)
	{
		while (arr[i])
		{
			cout << i << '\n';
			arr[i]--;
		}
	}



	return 0;
}