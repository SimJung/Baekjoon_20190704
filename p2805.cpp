#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> trees;
int h;

int holy(int start, int end)
{
	if (start == end)
		return start;

	int hh = (start + end) / 2;
	long long ans = 0;
	for (int i = trees.size() - 1; i >= 0; i--)
	{
		if (trees[i] > hh)
			ans += trees[i] - hh;
		else
			break;
	}
	
	if (h == ans)
		return hh;
	else if (h > ans)
		return holy(start, hh);
	else if (h < ans && start != hh)
		return holy(hh, end);
	else
		return hh;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, num, ans = 0, start, end, pos;
	cin >> t>>h;

	while (t--)
	{
		cin >> num;
		trees.push_back(num);
	}

	sort(trees.begin(), trees.end());
	start = 0;
	end = *(trees.end() - 1);

	cout << holy(start, end) << '\n';


	return 0;
}