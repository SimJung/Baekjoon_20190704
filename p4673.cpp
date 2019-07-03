#include <iostream>
#include <cmath>
using namespace std;

bool chk[10005];

int getlen(int n)
{
	int len = 1;
	while (n /= 10)
		len++;
	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	int len;
	for (int i = 1; i <= 10000; i++)
	{
		int sum = i;
		len = getlen(i);
		for (int j = 0; j < len; j++)
		{
			sum += int(i/pow(10.0, j))%10;
		}
		chk[sum] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!chk[i])
			cout << i<<'\n';
	}
	
	return 0;
}