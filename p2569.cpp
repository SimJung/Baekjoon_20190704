#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int floor = 0;

    for (int i = 0; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            floor++;
        }
        else if (arrangement[i] == ')') {
            //�������� ���
            if (arrangement[i - 1] == '(') {
                floor--;
                answer += floor;
            }
            //�ƴҰ��
            else {
                floor--;
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    string a = "()(((()())(())()))(())";
    cout << solution(a) << '\n';
}