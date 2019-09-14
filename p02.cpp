#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
string recur(string w)
{
	string u = "";
	string v = "";
	stack<char> s;
	bool isGood = 1;
	int chk1 = 0;
	int chk2 = 0;
	if (w == "")
		return w;
	for(int i=0; i<w.length(); i++)
	{
		if (w[i] == '(')
		{
			chk1++;
			s.push(w[i]);
		}
			
		if (w[i] == ')')
		{
			chk2++;
			if (!s.empty())
				s.pop();
			else
				isGood = 0;
		}
			
		u.push_back(w[i]);

		if (chk1 == chk2)
		{
			if (!s.empty())
				isGood = 0;

			break;
		}
	}
	for (int i = chk1 + chk2; i < w.length(); i++)
		v.push_back(w[i]);

	// u가 올바른 괄호 문자열
	if (isGood)
	{
		string holy = u + recur(v);
		return holy;
	}
	// u가 올바른 괄호 문자열이 아님
	else
	{
		string temp = "(";
		temp += recur(v);
		temp += ")";


		for (int i = 1; i < u.length()-1; i++)
		{
			if (u[i] == ')')
				u[i] = '(';
			else
				u[i] = ')';

			temp.push_back(u[i]);
		}
		return temp;
	}

}

string solution(string p) {
	string answer = "";

	if (p != "")
	{
		answer = recur(p);
	}
	return answer;
}

int main(void)
{
	string p1 = "(()())()";
	string p2 = ")(";
	string p3 = "()))((()";

	cout << solution(p1) << '\n';
	cout << solution(p2) << '\n';
	cout << solution(p3) << '\n';
	return 0;
}