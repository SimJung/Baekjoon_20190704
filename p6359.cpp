#include <iostream>
#include <cstring>
using namespace std;

bool arr[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num, sum;
	cin >> t;

	while (t--)
	{
		cin >> num;
		sum = 0;
		memset(arr, 0, num+1);
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (i * j > num) {
					break;
				}
				arr[i * j] = !arr[i * j];
			}
		}

		for (int i = 1; i <= num; i++) {
			sum += arr[i];
		}
		cout << sum << '\n';
	}
	return 0;
}