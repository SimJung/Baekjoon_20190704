#include <iostream>
#include <cmath>
#include <cstring>
#define MAXSIZE 100
using namespace std;

int arr[MAXSIZE];
int length;

void clearArr() {
	length = 1;
	memset(arr, 0, MAXSIZE * sizeof(int));
	arr[MAXSIZE - 1] = 2;
}

void showPow(int k) {
	for (int i = 0; i < k; i++) {
		for (int j = MAXSIZE - 1; j > MAXSIZE - 1 - length; j--) {
			arr[j] *= 2;
		}
		for (int j = MAXSIZE - 1; j > MAXSIZE - 1 - length; j--) {
			if (arr[j] >= 10) {
				arr[j] -= 10;
				arr[j - 1]++;
			}
		}
		if (arr[MAXSIZE - 1 - length] > 0) length++;
	}
	arr[MAXSIZE - 1]--;
	for (int i = MAXSIZE - 1; i > 0; i--) {
		if (arr[i] < 0) {
			arr[i] += 10;
			arr[i - 1]--;
			if (i - 1 == MAXSIZE - 1 - length && arr[i - 1] == 0)
				length--;
		}
		else
			break;
	}

	for(int i=MAXSIZE-length; i<MAXSIZE; i++){
		cout << arr[i];
	}
	cout << '\n';
}

void hanoi(int k, int start, int mid, int dest) {
	if (k >= 1) {
		hanoi(k - 1, start, dest, mid);
		cout << start << ' ' << dest << '\n';
		hanoi(k - 1, mid, start, dest);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	clearArr();
	showPow(k-1);
	if (k <= 20)
		hanoi(k, 1, 2, 3);
	return 0;
}