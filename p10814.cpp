#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct info
{
	int age;
	int idx;
	char name[101];
};

info arr[100001];

bool compare(info a, info b)
{
	if (a.age < b.age)
		return 1;
	else if (a.age == b.age)
	{
		if (a.idx < b.idx)
			return 1;
		else return 0;
	}
	else return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char name[101];
	int t, age;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].idx = i;
	}
	sort(arr, &arr[t], compare);

	for (int i = 0; i < t; i++)
	{
		cout << arr[i].age << ' ' << arr[i].name << '\n';
	}
	return 0;
}