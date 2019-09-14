#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	int button = 0;
	int hole = 0;
	bool chk = 1;

	int i_min=22, i_max=-1, j_min=22, j_max=-1;

	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock[i].size(); j++)
		{
			if (lock[i][j] == 0)
				hole++;
		}
	}

	for (int i = 0; i < key.size(); i++)
	{
		for (int j = 0; j < key[i].size(); j++)
		{
			if (key[i][j] == 0)
			{
				v.push_back(make_pair(i, j));
				button++;
				if (i_min > i)
					i_min = i;
				if (i_max < i)
					i_max = i;
				if (j_min > j)
					j_min = j;
				if (j_max < j)
					j_max = j;
			}
		}
	}

	if (hole > button)
	{
		answer = false;
		return answer;
	}
	else {
		for (int i = -i_max; i < i_max-i_min + 1; i++)
		{
			for (int j = -j_max; j < j_max - j_min + 1; j++)
			{
				button = 0;
				for (int k = 0; k < v.size(); k++)
				{
					int x = v[k].first + i;
					int y = v[k].second + j;

					if (x < 0 || y < 0 || x >= key[0].size() || y >= key.size())
						continue;

					if (lock[x][y] && key[x][y])
					{
						chk = false;
						break;
					}
					else if (!lock[x][y] && key[x][y])
						button++;
				}
				//맞는다는 뜻
				if (chk && hole == button)
				{
					answer = true;
					return answer;
				}
			}
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> k;
	vector<vector<int>> l;

	vector<int> temp1;
	{
		temp1.push_back(0);
		temp1.push_back(0);
		temp1.push_back(0);
		k.push_back(temp1);
		temp1.clear();

		temp1.push_back(1);
		temp1.push_back(0);
		temp1.push_back(0);
		k.push_back(temp1);
		temp1.clear();

		temp1.push_back(0);
		temp1.push_back(1);
		temp1.push_back(1);
		k.push_back(temp1);
		temp1.clear();

		temp1.push_back(1);
		temp1.push_back(1);
		temp1.push_back(1);
		l.push_back(temp1);
		temp1.clear();

		temp1.push_back(1);
		temp1.push_back(1);
		temp1.push_back(0);
		l.push_back(temp1);
		temp1.clear();

		temp1.push_back(1);
		temp1.push_back(0);
		temp1.push_back(1);
		l.push_back(temp1);
		temp1.clear();
	}
	
	cout << solution(k, l)<<'\n';

	return 0;
}