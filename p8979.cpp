#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct olim {
	int idx = 0;
	int medal[3] = { 0, 0, 0 };
} typedef ol;

bool compare(ol o1, ol o2) {
	if (o1.medal[0] != o2.medal[0])
		return o1.medal[0] > o2.medal[0];
	else {
		if (o1.medal[1] != o2.medal[1])
			return o1.medal[1] > o2.medal[1];
		else {
			return o1.medal[2] > o2.medal[2];
		}
	}
}

vector<ol> participants;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, num, m;
	cin >> n>>k;

	ol temp;
	for (int i = 0; i < n; i++) {
		cin >> num;
		temp.idx = num;
		for (int j = 0; j < 3; j++) {
			cin >> m;
			temp.medal[j] = m;
		}
		participants.push_back(temp);
	}

	sort(participants.begin(), participants.end(), compare);

	int minusVal = 0, answer;
	for (int i = 0; i < participants.size(); i++) {
		if (participants[i].idx == k) {
			answer = i + 1;
			for (int j = i - 1; j >= 0; j--) {
				for (int k = 0; k < 2; k++) {
					if (participants[j].medal[k] != participants[i].medal[k]) {
						cout << i + 1 - minusVal << '\n';
						return 0;
					}
				}
				minusVal++;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}