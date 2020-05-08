//#include <iostream>
//using namespace std;
//bool arr[201][201];
//bool visit[201];
//int ansArr[1001];
//
//int n, m, start = 0;
//bool answer = true;
//void dfs(int temp) {
//	for (int i = 1; i <= n; i++) {
//		if (!visit[i] && arr[temp][i]) {
//			visit[i] = 1;
//			dfs(i);
//		}
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j])
//				start = i;
//		}
//	}
//
//	dfs(start);
//
//	for (int i = 0; i < m; i++) {
//		cin >> ansArr[i];
//		if (!visit[ansArr[i]])
//			answer = false;
//	}
//
//	bool areSame = true;
//	for (int i = 1; i < m; i++) {
//		if (ansArr[i] != ansArr[i - 1]) {
//			areSame = false;
//			break;
//		}
//	}
//	answer = areSame ? true : answer;
//
//	cout << (answer ? "YES\n" : "NO\n");
//	return 0;
//}

#include <iostream>
using namespace std;

int parentArr[201];
int n, m;
int isConnected, rootVal;
bool answer = true;

int findRoot(int num) {
	if (parentArr[num] == num)
		return num;
	else
		return findRoot(parentArr[num]);
}

void unionFunc(int a, int b) {
	int ar = findRoot(a);
	int br = findRoot(b);
	if (ar > br)
		parentArr[ar] = br;
	else
		parentArr[br] = ar;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parentArr[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> isConnected;
			if (isConnected) {
				unionFunc(i, j);
			}
		}
	}

	cin >> isConnected;
	rootVal = findRoot(isConnected);
	for (int i = 1; i < m; i++) {
		cin >> isConnected;
		if (findRoot(isConnected) != rootVal)
			answer = false;
	}

	cout << (answer ? "YES\n" : "NO\n");
	return 0;
}