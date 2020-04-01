#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num;
	map<int, int> m;

	cin >> t;
	while (t--) {
		cin >> num;
		m[num]++;
	}

	cin >> t;
	while (t--) {
		cin >> num;
		cout << m[num] << ' ';
	}
	cout << '\n';

	
	return 0;
}