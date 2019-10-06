#include <iostream>
using namespace std;

bool earth[51][51];
int num = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h;
	
	while (cin >> w >> h)
	{
		num = 0;
		if (w == h && h == 0)
			return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> earth[i][j];
				if (earth[i][j])
				{
					bool i1=false, i2=false, i3=false, i4 = false;
					if (i >= 1 && earth[i - 1][j])
						i1 = true;
					if (j >= 1 && earth[i][j-1])
						i2 = true;
					if ((i >= 1 && j >= 1) && earth[i-1][j - 1])
						i3 = true;
					if ((i >= 1 && j < w - 1) && earth[i - 1][j + 1])
						i4 = true;

					if (!i1 && !i2 && !i3 && !i4)
						num++;
				}
			}
		}
		cout << num << "\n\n";
	}
	return 0;
}