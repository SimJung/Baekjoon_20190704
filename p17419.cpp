#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, nk=0, ans=0;
	string k;
	cin >> n>>k;
	for (int i = 0; i < k.length(); i++)
	{
		if (k[i] == '1')
			ans++;
	}
	cout << ans << '\n';

	return 0;
}