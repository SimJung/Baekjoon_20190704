#include <iostream>
using namespace std;

int arr[14];
int lts[7];
int k;

void lotto(int idx_lts, int idx_arr)
{
	if (idx_lts == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			cout << lts[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx_arr; i <= k; i++)
	{
		lts[idx_lts] = arr[i];
		lotto(idx_lts + 1, i+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;

		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
		}
		lotto(1, 1);
		cout << '\n';
	}
	return 0;
}