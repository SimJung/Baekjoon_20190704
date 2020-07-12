#include <iostream>
#include <vector>
#include <algorithm>
#define pi pair<int, int>
using namespace std;

vector<pi> constellation;
vector<pi> stars;

pi operator- (pi a, pi b) {
	return make_pair(a.first - b.first, a.second - b.second);
}

ostream &operator<< (ostream &output, pi a) {
	output <<  a.first << ' ' << a.second;
	return output;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	pi p;
	cin >> t;

	while (t--)
	{
		cin >> p.first >> p.second;
		constellation.push_back(p);
	}

	cin >> t;
	while (t--)
	{
		cin >> p.first >> p.second;
		stars.push_back(p);
	}

	sort(constellation.begin(), constellation.end());
	sort(stars.begin(), stars.end());
	
	for (int i = 0; i < stars.size() - constellation.size(); i++) {
		int contIdx = 1;
		for (int j = i + 1; j < stars.size(); j++) {
			if (stars[j] - stars[i] == constellation[contIdx] - constellation[0]) {
				contIdx++;
				if (contIdx == constellation.size()) break;
			}

			if (stars[j].first - stars[i].first > constellation[contIdx].first - constellation[0].first)
				break;
		}

		if (contIdx == constellation.size()) {
			cout << stars[i] - constellation[0] << '\n';
			return 0;
		}
	}

	return 0;
}