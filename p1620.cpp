#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, m;
map<string, int> names;
map<int, string> numbers;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		names[name] = i;
		numbers[i] = name;
	}

	string input;
	bool isNum = true;
	for (int i = 0; i < m; i++) {
		isNum = true;
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			if (!isdigit(input[j])) {
				isNum = false;
				break;
			}
		}

		if (isNum) {
			cout << numbers[stoi(input)] << '\n';
		}
		else
			cout << names[input] << '\n';
	}

	return 0;
}