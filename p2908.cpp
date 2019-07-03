#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string rs1, rs2, s1, s2;
	int n1, n2;
	cin >> rs1>>rs2;

	for (int i = rs1.length()-1; i >= 0; i--)
	{
		s1.push_back(rs1[i]);
		s2.push_back(rs2[i]);
	}

	n1 = stoi(s1);
	n2 = stoi(s2);

	if (n1 > n2)
		cout << n1 << '\n';
	else
		cout << n2 << '\n';



	return 0;
}