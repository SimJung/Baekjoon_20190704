#include <iostream>
#include <iomanip>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k;
	cin >> t;

	cout << fixed << setprecision(3);

	while (t--)
	{
		cin >> k;

		double sum = 0, num = 0;

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		for (int i = 0; i < k; i++)
		{
			if (sum / k < arr[i])
				num++;
		}

		cout << num / k * 100.0 << "%\n";
	}

	return 0;
}