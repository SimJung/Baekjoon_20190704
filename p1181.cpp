#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		if (a.compare(b) < 0)
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return a.length() < b.length();
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string strr;
	cin >> t;

	while(t--){
		cin >> strr;
		v.push_back(strr);
	}

	sort(v.begin(), v.end(), compare);

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}