#include <iostream>
using namespace std;

long long int maximum = 1e17;

struct big
{
	long long int low;
	long long int high;

};

big& operator+ (big& a, big b)
{
	a.high += b.high;
	if (a.low + b.low > maximum)
	{
		a.low = a.low + b.low - maximum;
		a.high++;
	}
	else
		a.low += b.low;
		
	return a;
}

ostream& operator<< (ostream& os, big& b)
{
	if(b.high)
		os << b.high << b.low;
	else
		os << b.low;
	return os;
}


big arr[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j].low = 1;
			else if (i == j)
				arr[i][j].low = 1;
			else if (j == 1)
				arr[i][j].low = i;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << endl;
	}*/
	cout << arr[n][m] << '\n';
	return 0;
}