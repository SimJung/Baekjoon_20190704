#include <iostream>
using namespace std;

int north, south, west, east, top, bottom;
int arr[21][21];
int si, sj, N, M, K, d;

void roll(int direction) {
	// 주사위 이동
	bool chk = false;
	switch (direction)
	{
	case 1:	// 동쪽
		if (sj < M - 1) {
			sj++;
			chk = true;
		}
		break;
	case 2:	// 서쪽
		if (sj > 0) {
			sj--;
			chk = true;
		}
		break;
	case 3:	// 북쪽
		if (si > 0) {
			si--;
			chk = true;
		}
		break;
	case 4:	// 남쪽
		if (si < N - 1) {
			si++;
			chk = true;
		}
		break;
	}
	if (!chk) return;

	// 주사위 회전
	int temp;
	switch (direction)
	{
	case 1:	// 동쪽
		temp = top;
		top = west;
		west = bottom;
		bottom = east;
		east = temp;
		break;
	case 2:	// 서쪽
		temp = top;
		top = east;
		east = bottom;
		bottom = west;
		west = temp;
		break;
	case 3:	// 북쪽
		temp = top;
		top = south;
		south = bottom;
		bottom = north;
		north = temp;
		break;
	case 4:	// 남쪽
		temp = top;
		top = north;
		north = bottom;
		bottom = south;
		south = temp;
		break;
	}

	// 지도의 밑면 확인
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