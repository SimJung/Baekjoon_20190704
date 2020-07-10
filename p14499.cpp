#include <iostream>
using namespace std;

int north, south, west, east, top, bottom;
int arr[21][21];
int si, sj, N, M, K, d;

void roll(int direction) {
	// �ֻ��� �̵�
	bool chk = false;
	switch (direction)
	{
	case 1:	// ����
		if (sj < M - 1) {
			sj++;
			chk = true;
		}
		break;
	case 2:	// ����
		if (sj > 0) {
			sj--;
			chk = true;
		}
		break;
	case 3:	// ����
		if (si > 0) {
			si--;
			chk = true;
		}
		break;
	case 4:	// ����
		if (si < N - 1) {
			si++;
			chk = true;
		}
		break;
	}
	if (!chk) return;

	// �ֻ��� ȸ��
	int temp;
	switch (direction)
	{
	case 1:	// ����
		temp = top;
		top = west;
		west = bottom;
		bottom = east;
		east = temp;
		break;
	case 2:	// ����
		temp = top;
		top = east;
		east = bottom;
		bottom = west;
		west = temp;
		break;
	case 3:	// ����
		temp = top;
		top = south;
		south = bottom;
		bottom = north;
		north = temp;
		break;
	case 4:	// ����
		temp = top;
		top = north;
		north = bottom;
		bottom = south;
		south = temp;
		break;
	}

	// ������ �ظ� Ȯ��
	if (arr[si][sj] == 0) {
		arr[si][sj] = bottom;
	}
	else {
		bottom = arr[si][sj];
		arr[si][sj] = 0;
 	}

	cout << top << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> si >> sj >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (K--) {
		cin >> d;
		roll(d);
	}
	return 0;
}