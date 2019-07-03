#include <iostream>
#include <string>
using namespace std;

int arr[9];
void init();
int val = 0;

void print()
{
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	string t;
	cin >> t;

	for (int i = 0; i < t.length(); i++)
	{
		if(t[i] - '0' == 9)
			arr[6]++;
		else
			arr[t[i] - '0']++;
	}

	init();
	cout << val << '\n';
	return 0;
}

bool empty()
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i])
		{
			return false;
		}
	}
	return true;
}

void init()
{
	while (!empty())
	{
		for (int i = 0; i < 9; i++)
		{
			if (arr[i])
			{
				if (i == 6)
				{
					if (arr[i] >= 2)
						arr[i] -= 2;
					else
						arr[i]--;
				}
				else
					arr[i]--;
			}
		}
		val++;
	}
}