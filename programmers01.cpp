#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> s;

string solution(vector<string> seoul) {
	string answer = "";
	vector<string>::iterator it = find(seoul.begin(), seoul.end(), "Kim");
	answer = "김서방은 ";
	int index = distance(seoul.begin(), it);
	answer.push_back((char)(index + '0'));
	answer += "에 있다";
	return answer;
}

int main(void)
{
	s.push_back("Jane");
	s.push_back("Kim");
	cout << solution(s) << '\n';
	return 0;
}