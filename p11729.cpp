#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int board, int from, int to, int mid)
{
	if (board > 1)
	{
		hanoi(board - 1, from, mid, to);
		cout << from << ' ' << to << '\n';
		hanoi(board - 1, mid, to, from);
	}
	else
		cout << from << ' ' << to << '\n';
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	cout << (pow(2.0, t) - 1) << '\n';
	hanoi(t, 1, 3, 2);
	return 0;
}