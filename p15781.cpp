#include <iostream>
using namespace std;

int helmet[1001];
int vest[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, h_max = 0, v_max=0;
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		cin >> helmet[i];
		if (h_max < helmet[i])
			h_max = helmet[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> vest[i];
		if (v_max < vest[i])
			v_max = vest[i];
	}
	cout << h_max + v_max << '\n';

	return 0;
}