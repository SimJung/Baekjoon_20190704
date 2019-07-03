#include <iostream>
using namespace std;

bool arr[42];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum=0;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		arr[n % 42] = 1;
	}
	for (int i = 0; i < 42; i++)
	{
		if (arr[i])
			sum++;
	}
	cout << sum << '\n';
	return 0;
}