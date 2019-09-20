#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> num;
		cout << binary_search(v.begin(), v.end(), num) << ' ';
	}
	cout << '\n';
	
	return 0;
}