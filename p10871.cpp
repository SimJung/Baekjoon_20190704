#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, stand;
	cin >> t>>stand;

	for (int i=0; i<t; i++)
	{
		cin>>arr[i];
	}

	for (int i = 0; i < t; i++)
	{
		if (arr[i] < stand)
			cout << arr[i]<<' ';
	}
	cout << '\n';

	return 0;
}