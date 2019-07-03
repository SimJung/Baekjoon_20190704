#include <iostream>
using namespace std;

int arr[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	double sum = 0, max = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	for (int i = 0; i < t; i++)
	{
		sum += (double)arr[i] / max * 100;
	}

	cout << sum / (double)t << '\n';



	return 0;
}