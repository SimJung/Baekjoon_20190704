#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, newa, newb;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '6')
			newa.push_back('5');
		else
			newa.push_back(a[i]);
	}

	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == '6')
			newb.push_back('5');
		else
			newb.push_back(b[i]);
	}
	cout<<stoi(newa) + stoi(newb)<<' ';

	for (int i = 0; i < newa.length(); i++)
	{
		if (newa[i] == '5')
			newa[i] = '6';
	}

	for (int i = 0; i < newb.length(); i++)
	{
		if (newb[i] == '5')
			newb[i] = '6';
	}
	cout << stoi(newa) + stoi(newb) << '\n';
	return 0;
}