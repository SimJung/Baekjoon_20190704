#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> parentMap;
map<string, int> friendDeg;

string findRoot(string name) {
	if (parentMap[name] == name){
		return name;
	}
	else{
		return findRoot(parentMap[name]);
	}
}

void cntRoot(string name) {
	if (parentMap[name] == name) {
		return ;
	}
	else {
		friendDeg[parentMap[name]] = friendDeg[parentMap[name]] < friendDeg[name] + 1 ? friendDeg[name]+1 : friendDeg[parentMap[name]];
		return cntRoot(parentMap[name]);
	}
}

void unionFriend(string a, string b) {
	string ar = findRoot(a);
	string br = findRoot(b);
	cntRoot(a);
	cntRoot(b);
	if (ar > br) {
		parentMap[ar] = br;
		friendDeg[br] += friendDeg[ar];
	}
	else {
		parentMap[br] = ar;
		friendDeg[ar] += friendDeg[br];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	string name1, name2;
	cin >> t;

	while (t--)
	{
		cin >> n;
		parentMap.clear(); friendDeg.clear();
		for (int i = 0; i < n; i++) {
			cin >> name1 >> name2;
			if (parentMap.find(name1) == parentMap.end())
			{
				parentMap[name1] = name1;
				friendDeg[name1] = 1;
			}
			if (parentMap.find(name2) == parentMap.end())
			{
				parentMap[name2] = name2;
				friendDeg[name2] = 1;
			}
			
			unionFriend(name1, name2);

			cout << friendDeg[findRoot(name1)] << '\n';
		}
	}
	return 0;
}