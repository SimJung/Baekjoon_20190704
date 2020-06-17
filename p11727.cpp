#include <iostream>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= t; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2)%10007;
	}
	cout<<arr[t]<<'\n';
	return 0;
}