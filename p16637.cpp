///*
//���� �ִ� 20�� �̳����� ��ȣ�� �̸����� �߰��� �ִ��� ���ϴ�
//������ ����� �����̴�.
//��ȣ�� �߰��Ѵٴ� ���� �켱������ �ٲٴ� ���̱� ������
//�ٸ� ������ ���ϴ� next_permutation���ε� ������ ���̶� �Ǵ��ߴ�.
//������ ���ڵ� �ٲ��� �ϴµ� �����ڸ� �ٲ�� ���� ���� ���ؼ� �����̴�.
//
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<char> ops;
//vector<int> nums;
//
//bool isDigit(char c)
//{
//	return ((int)c >= (int)'0' && (int)c <= '9');
//}
//
////chk = 1 �̸� ��ȣ�϶�, 0�̸� ��ȣ�� �ƴ� ��
//void eval(bool chk)
//{
//	int n1, n2, res;
//	char op;
//
//	do
//	{
//		n1 = nums[0];
//		nums.erase(nums.begin());
//		n2 = nums[0];
//		nums.erase(nums.begin());
//
//		op = ops.top();
//		ops.pop();
//
//		switch (op)
//		{
//		case '+':
//			res = n1 + n2;
//			nums.push(res);
//			break;
//
//		case '-':
//			res = n2 - n1;
//			nums.push(res);
//			break;
//
//		case '*':
//			res = n1 * n2;
//			nums.push(res);
//			break;
//
//		case ')':
//			chk = 0;
//			break;
//		}
//	} while (chk);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int t;
//	string st;
//	cin >> t >> st;
//
//	for (int i = st.length()-1; i >= 0; i--)
//	{
//		// �����϶�
//		if (isDigit(st[i]))
//			nums.push_back((int)st[i] - (int)'0');
//
//		// �������϶�
//		else if (st[i] != '(')
//			ops.push_back(st[i]);
//
//		// ��ȣ�� ������
//		else
//			eval(1);
//	}
//	while (!ops.empty())
//		eval(0);
//
//	cout << nums[0] << '\n';
//
//	return 0;
//}