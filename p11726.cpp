//#include <iostream>
//using namespace std;
//
//int arr[1001];
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int t;
//	cin >> t;
//
//	arr[0] = 1;
//	arr[1] = 2;
//
//	for (int i = 2; i < t; i++)
//	{
//		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
//	}
//	cout << arr[t - 1]<<'\n';
//	return 0;
//}


//				위쪽은 for문

// -------------------------------------------------------

//				아래쪽은 재귀


#include <iostream>
using namespace std;

int arr[1001];

int getTile(int n)
{
	if (arr[n] == 0)
	{
		if (n <= 1)
			arr[n] = 1;
		else if (n == 2)
			arr[n] = 2;
		else
			arr[n] = (getTile(n - 1) + getTile(n - 2)) % 10007;

		return arr[n];
	}
	else
		return arr[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	cout << getTile(t) << '\n';

	return 0;
}