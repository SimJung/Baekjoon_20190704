#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum{HEAD, TAIL, ALL};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	// 0 : 시작, 1 : 끝, 2 : 전부
	for (int i = 0; i < queries.size(); i++)
	{
		int type;
		int ans = 0;
		string key;
		string val;

		int qlen = queries[i].length() - 1;

		if (queries[i][0] == '?' && queries[i][qlen] == '?')
			type = ALL;
		else if (queries[i][0] == '?')
			type = HEAD;
		else
			type = TAIL;

		if (type == ALL)
		{
			for (int j = 0; j < words.size(); j++)
			{
				if (words[j].size() == queries[i].size())
					ans++;
			}
			answer.push_back(ans);
		}
		else if (type == HEAD)
		{
			int len = 0;
			
			for (int j = 1; j < queries[i].size(); j++)
			{
				if (queries[i][j] != '?')
				{
					len = j;
					break;
				}
			}
			key = queries[i].substr(len, queries[i].size() - len);
			
			for (int j = 0; j < words.size(); j++)
			{
				val = words[j].substr(len, words[j].size());
				if (key == val && queries[i].size() == words[j].size())
					ans++;
			}
			answer.push_back(ans);
		}
		else {
			int idx = queries[i].find('?');
			key = queries[i].substr(0, idx);
			for (int j = 0; j < words.size(); j++)
			{
				val = words[j].substr(0, idx);
				if (key == val && queries[i].size() == words[j].size())
					ans++;
			}
			answer.push_back(ans);
		}
	}
	return answer;
}

int main(void)
{
	vector<string> words;
	vector<string> queries;

	words.push_back("frodo");
	words.push_back("front");
	words.push_back("frost");
	words.push_back("frozen");
	words.push_back("frame");
	words.push_back("kakao");

	queries.push_back("?????");
	queries.push_back("fro??");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");
	

	vector<int> ans = solution(words, queries);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}