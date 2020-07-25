#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string source;
	string part;

	getline(cin, source);
	getline(cin, part);

	int answer = 0, pos = 0;
	while ((pos = source.find(part, pos)) != -1) {
		source.erase(pos, part.length());
		answer++;
	}

	cout << answer << '\n';
	return 0;
}