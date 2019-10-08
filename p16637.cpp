/*
���� �ִ� 20�� �̳����� ��ȣ�� �̸����� �߰��� �ִ��� ���ϴ�
������ ����� �����̴�.
��ȣ�� �߰��Ѵٴ� ���� �켱������ �ٲٴ� ���̱� ������
�ٸ� ������ ���ϴ� next_permutation���ε� ������ ���̶� �Ǵ��ߴ�.

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