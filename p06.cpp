#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	return answer;
}

int main(void)
{
	vector<int> weak;
	vector<int> dist;

	weak.push_back(1);
	weak.push_back(5);
	weak.push_back(6);
	weak.push_back(10);

	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);
	dist.push_back(4);

	cout << solution(12,weak,dist) << '\n';
	weak.clear();
	dist.clear();
	
	weak.push_back(1);
	weak.push_back(3);
	weak.push_back(4);
	weak.push_back(9);
	weak.push_back(10);

	dist.push_back(3);
	dist.push_back(5);
	dist.push_back(7);
	cout << solution(12, weak, dist) << '\n';


	return 0;
}