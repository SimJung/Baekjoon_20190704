#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[16];
char password[16];

void backtrack(int nowidx, int i_start)
{
	if (nowidx == L) {
		bool chk = false;
		int num = 0;
		for (int i = 0; i < L; i++) {
			switch (password[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				chk = true;
				break;

			default:
				num++;
			}
			if (chk && num >= 2)
				break;
		}
		if(chk && num >= 2)
			cout << password << '\n';
		return;
	}

	for (int i = i_start; i < C; i++) {
		if (i >= C)
			continue;
		password[nowidx] = arr[i];
		backtrack(nowidx + 1, i+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + C);

	backtrack(0, 0);
	return 0;
}