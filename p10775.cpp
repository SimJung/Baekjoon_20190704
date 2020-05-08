#include <iostream>
using namespace std;

int gate[100002];
int g, p, gi, num = 0;
bool answer = true;

int find(int n) {
	if (gate[n] == n) return n;
	
	return gate[n] = find(gate[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		gate[i] = i;
	}
	
	int root;
	for (int i = 0; i < p; i++) {
		cin >> gi;
		root = find(gi);
		if (answer && root != 0) {
			num++;
			gate[root] = root - 1;
		}
		else {
			answer = false;
		}
	}

	cout << num << '\n';
	return 0;
}