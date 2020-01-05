#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int t;
string numbers[1001];

bool comp(string a, string b) {
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				return a[i] > b[i];
		}
	}
	else {

	}
}

void showStr() {
	for (int i = 0; i < t; i++)
		cout << numbers[i] << ' ';
	cout << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> numbers[i];
	}

	sort(numbers, &numbers[t], comp);
	showStr();
	return 0;
}