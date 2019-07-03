#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, sum = 0;
	cin >> k;

	for (int i = k; i > 0; i -= 3)
	{
		if (i % 5)
		{
			sum++;
			k -= 3;
		}else	// 5로 나누어 떨어질경우
		{
			sum += i / 5;
			k = 0;
			break;
		}
	}

	if (k)
		cout << "-1" << endl;
	else
		cout << sum << endl;

	return 0;
}