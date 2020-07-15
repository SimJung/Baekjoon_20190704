#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		for (int j = 1; j < t - i; j++) 
			cout << ' ';
		for (int j = 0; j < i; j++)
			cout << '*';
		cout << '*';
		for (int j = 0; j < i; j++)
			cout << '*';

		if(i != t-1)
		cout<<'\n';

	}
	return 0;
}