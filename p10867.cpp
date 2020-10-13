#include <iostream>
using namespace std;
int arr[2002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int temp;
	while (t--)
	{
		cin >> temp;
		arr[temp+1000]++;
	}

	for (int i = 0; i < 2002; i++) {
		if (arr[i]) cout << i-1000 << ' ';
	}
	cout << '\n';
	return 0;
}