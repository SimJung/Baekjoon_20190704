#include <iostream>
using namespace std;

int arr[51];
int nodeNum;
int leafNum;
int rootNum;

void getLeafNum(int idx) {
	if (idx > nodeNum || arr[idx] == -1)
		return;

	if (arr[idx * 2] == 0 && arr[idx * 2 + 1] == 0) {
		leafNum++;
		return;
	}
	else {
		getLeafNum(idx * 2);
		getLeafNum(idx * 2 + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodeNum;

	for (int i = 1; i <= nodeNum; i++) {
		cin >> arr[i];
		if (arr[i] == -1) {
			rootNum = i;
		}
		arr[i]++;
	}

	int delNode;
	cin >> delNode;
	arr[delNode+1] = -1;

	getLeafNum(1);

	cout << leafNum << '\n';
	
	return 0;
}