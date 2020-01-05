#include <iostream>
using namespace std;

int gan[] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
char izi[] = {'I', 'J', 'K', 'L', 'A', 'B', 'C', 'D', 'E', 'F', 'G',  'H'};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
		cout <<izi[t% 12] << gan[t% 10] << '\n';
	

	return 0;
}