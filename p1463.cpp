#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int t, val = 0;

int getCount(int num)
{
	for (int i = 4; i <= num; i++)
	{
		int minn = i+1;
		if (i % 3 == 0 && i % 2 == 0)
		{
			minn = min(dp[i / 3], dp[i / 2]);
			minn = min(minn, dp[i - 1]);

		}
		else if (i % 3 == 0)
		{
			minn = min(dp[i / 3], dp[i - 1]);
		}
			
		else if (i % 2 == 0)
		{
			minn = min(dp[i / 2], dp[i - 1]);
		}
			
		else
		{
			minn = dp[i - 1];
		}
			

		dp[i] = minn + 1;
	}
	return dp[num];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> t;

	dp[2] = 1;
	dp[3] = 1;
		
	cout << getCount(t) << '\n';


	return 0;
}