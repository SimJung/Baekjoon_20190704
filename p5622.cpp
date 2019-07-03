#include <iostream>
#include <string>
using namespace std;

int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string phone;
	cin >> phone;

	int sum = 0;

	for (int i = 0; i < phone.length(); i++)
	{
		sum += arr[phone[i] - 'A'];
	}

	cout << sum << '\n';

	return 0;
}