#include <iostream>
using namespace std;

int arr[100001];
int num;
int chk = 0;
bool answer;

void getTeam(int origin, int now)
{
	if (arr[now] == origin)
	{
		answer = true;
		return;
	}
	else if (chk < num)
	{
		chk++;
		getTeam(origin, arr[now]);
	}
	else
	{
		chk = 0;
		answer = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int val = 0;
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= num; i++)
		{
			getTeam(i, i);
			if (answer)
				val++;
		}
		cout << num - val << '\n';
	}
	return 0;
}