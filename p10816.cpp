#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num;
	cin >> t;

	while (t--) {
		cin >> num;
		arr[num]++;
	}

	cin >> t;

	
	return 0;
}