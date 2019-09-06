#include <string>
#include <vector>
#include <map>

using namespace std;

multimap<string, bool> m;
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";


	for (int i = 0; i < participant.size(); i++)
		m.insert(make_pair(participant[i], 0));

	for (int i = 0; i < completion.size(); i++)
	{
		multimap<string, bool>::iterator itr = m.find(completion[i]);
		m.erase(itr);
	}

	for (multimap<string, bool>::iterator itr = m.begin(); itr != m.end(); itr++)
	{
		if (itr->first != "")
		{
			answer = itr->first;
			break;
		}
	}
	return answer;
}