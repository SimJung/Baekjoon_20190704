#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans=0;
	cin >> t;

	v.push_back(0);

	for (int i = 1; i <= t; i++)
		cin >> arr[i];

	for (int i = 1; i <= t; i++)
	{
		if (v.back() < arr[i])
		{
			ans++;
			v.push_back(arr[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << ans << '\n';
	return 0;
}