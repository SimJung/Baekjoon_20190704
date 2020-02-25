#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (answer < arr[i])
            answer = arr[i];
    }
    bool chk = true;
    while (true) {
        chk = true;
        for (int i = 0; i < arr.size(); i++) {
            if (answer % arr[i]) {
                chk = false;
                break;
            }
        }

        if (chk) {
            break;
        }
        else
            answer++;
    }
    return answer;
}

int main() {
    vector<int> a = { 2, 6, 8, 14 };
    cout << solution(a) << '\n';
}