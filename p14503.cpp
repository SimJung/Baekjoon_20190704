#include <iostream>
#define pi pair<int, int>
using namespace std;

int answer, N, M, direction, ri, rj;
bool room[51][51];
bool cleanArea[51][51];

void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == ri && j == rj) {
				if (direction == 0)
					cout << "↑";
				else if (direction == 1)
					cout << "→";
				else if (direction == 2)
					cout << "↓";
				else
					cout << "←";
			}
			else {
				if (room[i][j] == 0) {
					if (cleanArea[i][j] == 0)
						cout << "○";
					else
						cout << "★";
				}
				else {
					cout << "■";
				}
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

bool movable(int i, int j) {
	return (room[i][j] == 0 && cleanArea[i][j] == 0);
}

bool getBack() {
	if (direction == 0) {	// 북쪽
		if (ri < N-1 && !room[ri+1][rj]) {
			ri = ri + 1;
			return true;
		}
	}
	else if (direction == 1) { // 동쪽
		if (rj > 0 && !room[ri][rj-1]) {
			rj = rj - 1;
			return true;
		}
	}
	else if (direction == 2) { // 남쪽
		if (ri > 0 && !room[ri - 1][rj]) {
			ri = ri - 1;
			return true;
		}
	}
	else { // 서쪽
		if (rj < M-1 && !room[ri][rj+1]) {
			rj = rj + 1;
			return true;
		}
	}

	return false;
}

void clean() {
	while (true) {
		// 해당 자리 청소
		if (!cleanArea[ri][rj]) {
			cleanArea[ri][rj] = 1;
			answer++;
		}

		// 탐색 진행
		bool rotate = true;
		int search_d = direction - 1;
		if (search_d == -1)
			search_d = 3;

		for (int i = 0; i < 4; i++) {
			if (search_d == 0) {	// 북쪽
				if (ri > 0 && movable(ri - 1, rj)) {
					ri = ri - 1;
					break;
				}
			}
			else if (search_d == 1) { // 동쪽
				if (rj < M-1 && movable(ri, rj+1)) {
					rj = rj + 1;
					break;
				}
			}
			else if (search_d == 2) { // 남쪽
				if (ri < N-1 && movable(ri + 1, rj)) {
					ri = ri + 1;
					break;
				}
			}
			else { // 서쪽
				if (rj > 0 && movable(ri, rj - 1)) {
					rj = rj - 1;
					break;
				}
			}

			if (i == 3){
				rotate = false;
				break;
			}

			search_d--;
			if (search_d == -1)
				search_d = 3;
		}

		// 4방향 이동 불가
		if (!rotate) {
			if (!getBack())
				return;
		}
		// 이동 완료
		else {
			direction = search_d;
		}

		//show();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> ri>>rj>>direction;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	clean();

	cout << answer << '\n';
	
	return 0;
}