#include <iostream>
#include <string>
using namespace std;

int arr[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string name;
	string answer = "";
	cin >> t;

	while (t--)
	{
		cin >> name;
		arr[name[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			answer += i + 'a';
		}
	}

	if (answer == "")
		cout << "PREDAJA\n";
	else
		cout << answer<<'\n';
	return 0;
}