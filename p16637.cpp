///*
//대충 최대 20자 이내에서 괄호를 이리저리 추가해 최댓값을 구하는
//공식을 만드는 내용이다.
//괄호를 추가한다는 것은 우선순위를 바꾸는 것이기 때문에
//다른 순열을 구하는 next_permutation으로도 가능할 것이라 판단했다.
//하지만 숫자도 바뀌어야 하는데 연산자만 바뀌는 것을 생각 못해서 오답이다.
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
////chk = 1 이면 괄호일때, 0이면 괄호가 아닐 때
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
//		// 숫자일때
//		if (isDigit(st[i]))
//			nums.push_back((int)st[i] - (int)'0');
//
//		// 연산자일때
//		else if (st[i] != '(')
//			ops.push_back(st[i]);
//
//		// 괄호를 닫으면
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