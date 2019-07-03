#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + t);

	for (int i = 0; i < t; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';

	return 0;
}