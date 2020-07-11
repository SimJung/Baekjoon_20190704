#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, answer, tempAnswer;
string str[51];
vector<char> strAlpha[51];
vector<char> used;
string learnAlpha = "abcdefghijklmnopqrstuvwxyz";
bool boolLearnAlpha[27];

void backtrack(int cnt, int now_idx) {
	if (cnt == k - 5 || cnt >= used.size()) {
		for (int i = 0; i < k-5; i++) {
			boolLearnAlpha[learnAlpha[i] - 'a'] = 1;
		}

		for (int i = 0; i < n; i++) {
			bool chk = true;
			for (int j = 0; j < strAlpha[i].size(); j++) {
				if (!boolLearnAlpha[strAlpha[i][j] - 'a']) {
					chk = false;
					break;
				}
			}

			if (chk)
				tempAnswer++;
		}

		if (answer < tempAnswer)
			answer = tempAnswer;
		tempAnswer = 0;

		for (int i = 0; i < k-5; i++) {
			boolLearnAlpha[learnAlpha[i] - 'a'] = 0;
		}
	}
	else {
		for (int i = now_idx; i < used.size(); i++) {
			learnAlpha[cnt] = used[i];
			backtrack(cnt + 1, i + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (k < 5) {
		cout << "0\n";
		return 0;
	}
		

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 4; j < str[i].length() - 4; j++) {
			if (str[i][j] == 'a' || str[i][j] == 'n' || str[i][j] == 't' || str[i][j] == 'i' || str[i][j] == 'c')
				continue;

			strAlpha[i].push_back(str[i][j]);
			used.push_back(str[i][j]);
		}

		sort(strAlpha[i].begin(), strAlpha[i].end());
		strAlpha[i].erase(unique(strAlpha[i].begin(), strAlpha[i].end()), strAlpha[i].end());
	}

	sort(used.begin(), used.end());
	used.erase(unique(used.begin(), used.end()), used.end());
	backtrack(0, 0);

	cout << answer << '\n';

	return 0;
}