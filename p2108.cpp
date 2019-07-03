#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int arr[500002];
int countt[8002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed << setprecision(0);
	int t, maxx = -1;
	double sum = 0;
	vector<int> v;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		countt[arr[i] + 4000]++;
		maxx = max(maxx, countt[arr[i] + 4000]);
	}

	for (int i = 0; i < 8002; i++)
	{
		if (countt[i] == maxx)
			v.push_back(i - 4000);
	}

	sort(v.begin(), v.end());
	sort(arr, &arr[t]);

	cout << double( sum / t) << '\n';
	cout << arr[t/2] << '\n';

	if (v.size() == 1)
		cout << v[0] << '\n';
	else
		cout << v[1] << '\n';

	cout << arr[t-1]-arr[0] << '\n';



	return 0;
}