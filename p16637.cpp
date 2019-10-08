/*
대충 최대 20자 이내에서 괄호를 이리저리 추가해 최댓값을 구하는
공식을 만드는 내용이다.
괄호를 추가한다는 것은 우선순위를 바꾸는 것이기 때문에
다른 순열을 구하는 next_permutation으로도 가능할 것이라 판단했다.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void show_vector(vector<T> v)
{
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << ' ';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string st;
	cin >> t>>st;
	
	vector<int> v_n;
	vector<char> v_c;

	for (int i = 0; i < st.length(); i++)
	{
		if (i % 2)
			v_c.push_back(st[i]);
		else
			v_n.push_back(st[i] - '0');
	}

	do
	{
		show_vector(v_c);
	} while (next_permutation(v_c.begin(), v_c.end()));
	
	

	return 0;
}