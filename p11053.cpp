//#include <iostream>
//using namespace std;
//
//int ans[1001];
//int arr[1001];
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int t, maxx=0;
//	cin >> t;
//
//	for (int i = 0; i < t; i++)
//		cin >> arr[i];
//
//	for (int i = 1; i < t; i++)
//	{
//		for (int j = i; j < t; j++)
//		{
//			if (arr[i - 1] < arr[j])
//			{
//				if (ans[i - 1] + 1 > ans[j])
//					ans[j] = ans[i - 1] + 1;
//			}
//
//			if (maxx < ans[j])
//				maxx = ans[j];
//		}
//	}
//
//	cout << maxx+1 << '\n';
//
//	return 0;
//}


//==========================================================

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{

	}

	return 0;
}