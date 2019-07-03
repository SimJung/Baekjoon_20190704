#include <iostream>
using namespace std;

int x_arr[1001];
int y_arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	x_arr[x1]++; x_arr[x2]++; x_arr[x3]++;
	y_arr[y1]++; y_arr[y2]++; y_arr[y3]++;

	if (x_arr[x1] == 1)
		cout << x1 << ' ';
	if (x_arr[x2] == 1)
		cout << x2 << ' ';
	if (x_arr[x3] == 1)
		cout << x3 << ' ';

	if (y_arr[y1] == 1)
		cout << y1 << '\n';
	if (y_arr[y2] == 1)
		cout << y2 << '\n';
	if (y_arr[y3] == 1)
		cout << y3 << '\n';
	return 0;
}