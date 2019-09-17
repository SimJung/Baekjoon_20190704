#include <iostream>
using namespace std;

int arr[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
		arr[a[i] - 97]++;
	for (int i = 0; i < 26; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}