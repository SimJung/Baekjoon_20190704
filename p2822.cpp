#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> arr;
	vector<int> v;
	int score, sum = 0;
	for (int i = 0; i < 8; i++) {
		cin >> score;
		arr.push_back(make_pair(score, i + 1));
	}
	sort(arr.begin(), arr.end(), compare);

	sum = arr[0].first + arr[1].first + arr[2].first + arr[3].first + arr[4].first;
	cout << sum << '\n';
	
	for (int i = 0; i < 5; i++)
		v.push_back(arr[i].second);

	sort(v.begin(), v.end());
	for (int i = 0; i < 5; i++) {
		cout << v[i] << ' ';
	}
	
	return 0;
}