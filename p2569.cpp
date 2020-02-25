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
            //레이져일 경우
            if (arrangement[i - 1] == '(') {
                floor--;
                answer += floor;
            }
            //아닐경우
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