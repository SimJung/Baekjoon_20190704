#include <iostream>
#include <cstring>
using namespace std;
int n1, n2;
int arr[9];
bool visit[9];
int p;

void print(int idx, int sz) {
	bool chk = false;
	if (sz == n2) {
		for (int i = 0; i < n2; i++) {
			cout << arr[i]<<' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n1; i++) {
			if (!visit[i]) {
				arr[idx] = i;
				visit[i] = true;
				print(idx + 1, sz + 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;
	print(0, 0);

	return 0;
}