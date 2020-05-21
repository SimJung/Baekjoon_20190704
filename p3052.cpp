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

//arr은 42개, 10개 입력받아서 42 나머지에 해당하는 곳은 체크, 체크된 곳 모두 합산.