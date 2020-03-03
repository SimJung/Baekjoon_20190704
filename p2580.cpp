#include <iostream>
using namespace std;

int zeronum;
int arr[10][10];

//행[가로]
bool row[10][10];
//열[세로]
bool col[10][10];
//사각 영역
bool sqr[10][10];

void show() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void showsqr() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << sqr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sudoku(int n) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (!arr[n][i] && !row[n][j] && !col[i][j] && !sqr[(n - 1) * 3 + i][j]) {
				row[n][j] = 1;
				col[i][j] = 1;
				sqr[(n - 1) * 3 + i][j] = 1;
				arr[n][i] = j;
				zeronum--;

				
				cout <<zeronum<< "(" << n << "," << i << ") : " << j << '\n';
				show();
				cout << "\n";
				

				if (zeronum != 0)
					sudoku(n + 1);
				else
					return;
				if (zeronum == 0)
					return;
				else {
					row[n][j] = 0;
					col[i][j] = 0;
					sqr[(n - 1) * 3 + i][j] = 0;
					arr[n][i] = 0;
					zeronum++;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			row[i][arr[i][j]] = 1;
			col[j][arr[i][j]] = 1;
			a = ((i - 1) / 3)+1;
			b = ((j - 1) / 3)+1;
			sqr[(a - 1) * 3 + b][arr[i][j]] = 1;
			if (arr[i][j] == 0)
				zeronum++;
		}
	}
	sudoku(1);

	show();

	return 0;
}