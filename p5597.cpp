#include <iostream>
using namespace std;

bool arr[31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	for (int i = 0; i < 28; i++) {
		cin >> n;
		arr[n] = 1;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}
	return 0;
}