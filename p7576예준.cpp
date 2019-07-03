// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct DATA
{
	int Height;
	int Weight;
};

int main()
{
	queue<DATA> Q;
	int N, M; // N 세로, M 가로
	int ** Tomato;
	int ** DistanceMap;
	int biggest = 0;

	cin >> M >> N;
	Tomato = new int*[N];
	DistanceMap = new int*[N];
	for (int i = 0; i <= N; i++)
	{
		Tomato[i] = new int[M];
		DistanceMap[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DistanceMap[i][j] = -1;
			cin >> Tomato[i][j];
			if (Tomato[i][j] == 1)
			{
				DATA asd;
				asd.Height = i;
				asd.Weight = j;
				Q.push(asd);
				DistanceMap[i][j] = 0;
			}
		}
	}
	DATA dataTemp;
	DATA dataTemp2;
	while (Q.size() > 0)
	{
		dataTemp = Q.front();
		if (dataTemp.Height + 1 < N)
		{
			if (Tomato[dataTemp.Height + 1][dataTemp.Weight] != -1)
			{
				if (DistanceMap[dataTemp.Height + 1][dataTemp.Weight] == -1 || DistanceMap[dataTemp.Height + 1][dataTemp.Weight] > DistanceMap[dataTemp.Height][dataTemp.Weight])
				{
					DistanceMap[dataTemp.Height + 1][dataTemp.Weight] = DistanceMap[dataTemp.Height][dataTemp.Weight] + 1;
					dataTemp2.Height = dataTemp.Height + 1;
					dataTemp2.Weight = dataTemp.Weight;
					Q.push(dataTemp2);
				}
			}
		}
		if (dataTemp.Height - 1 >= 0)
		{
			if (Tomato[dataTemp.Height - 1][dataTemp.Weight] != -1)
			{
				if (DistanceMap[dataTemp.Height - 1][dataTemp.Weight] == -1 || DistanceMap[dataTemp.Height - 1][dataTemp.Weight] > DistanceMap[dataTemp.Height][dataTemp.Weight])
				{
					DistanceMap[dataTemp.Height - 1][dataTemp.Weight] = DistanceMap[dataTemp.Height][dataTemp.Weight] + 1;
					dataTemp2.Height = dataTemp.Height - 1;
					dataTemp2.Weight = dataTemp.Weight;
					Q.push(dataTemp2);
				}
			}
		}
		if (dataTemp.Weight + 1 < M)
		{
			if (Tomato[dataTemp.Height][dataTemp.Weight + 1] != -1)
			{
				if (DistanceMap[dataTemp.Height][dataTemp.Weight + 1] == -1 || DistanceMap[dataTemp.Height][dataTemp.Weight + 1] > DistanceMap[dataTemp.Height][dataTemp.Weight])
				{
					DistanceMap[dataTemp.Height][dataTemp.Weight + 1] = DistanceMap[dataTemp.Height][dataTemp.Weight] + 1;
					dataTemp2.Height = dataTemp.Height;
					dataTemp2.Weight = dataTemp.Weight + 1;
					Q.push(dataTemp2);
				}
			}
		}
		if (dataTemp.Weight - 1 >= 0)
		{
			if (Tomato[dataTemp.Height][dataTemp.Weight - 1] != -1)
			{
				if (DistanceMap[dataTemp.Height][dataTemp.Weight - 1] == -1 || DistanceMap[dataTemp.Height][dataTemp.Weight - 1] > DistanceMap[dataTemp.Height][dataTemp.Weight])
				{
					DistanceMap[dataTemp.Height][dataTemp.Weight - 1] = DistanceMap[dataTemp.Height][dataTemp.Weight] + 1;
					dataTemp2.Height = dataTemp.Height;
					dataTemp2.Weight = dataTemp.Weight - 1;
					Q.push(dataTemp2);
				}
			}
		}
		if (!Q.empty()) Q.pop();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Tomato[i][j] != -1 && DistanceMap[i][j] == -1)
			{
				cout << -1;
				for (int i = 0; i <= N; i++)
				{
					delete Tomato[i];
					delete DistanceMap[i];
				}
				delete Tomato;
				delete DistanceMap;
				return 0;
			}
			if (DistanceMap[i][j] > biggest) biggest = DistanceMap[i][j];
		}
	}
	cout << biggest;
	for (int i = 0; i <= N; i++)
	{
		delete Tomato[i];
		delete DistanceMap[i];
	}
	delete Tomato;
	delete DistanceMap;
	return 0;
}