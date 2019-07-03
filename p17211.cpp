#include <iostream>
#include <iomanip>
using namespace std;

int n;
bool ye;
float gg, gb, bg, bb, g=1, b=1, ng, nb;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> ye;
	cin >> gg >> gb >> bg >> bb;
	
	

	n--;
	while (n--)
	{
		if (ye)
		{
			g = gg;
			b = gb;
		}
		else
		{
			g = bg;
			b = bb;
		}
		ng = g*gg + b*bg;
		nb = g*gb + b*bb;
		cout << ng << nb << endl;
	}
	cout << setprecision(1);
	cout << ng * 1000 << '\n' << nb * 1000 << '\n';
	return 0;
}