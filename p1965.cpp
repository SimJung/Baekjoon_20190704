#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2000000000

int box[1001];
int dp[1001];

//1번 : dp줄, 2번 : 크기줄
int lis_d[1001];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.push_back(-INF);
	int t, ans=0;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> box[i];
	}

	for (int i = 1; i <= t; i++)
	{
		lower_bound(v.begin, v.end, box[i]);
		
	}
	return 0;
}