#include <iostream>
using namespace std;

bool arr[1000001];	//false : prime number

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2;
	cin >> n1>>n2;

	arr[1] = true;
	for (int i = 2; i <= n2; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; j <= n2 / i; j++)
			{
				arr[i*j] = true;
			}
		}
	}

	for (int i = n1; i <= n2; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}

	return 0;
}