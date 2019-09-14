#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a = "????hello";
	string b = a.substr(5, a.length() - 5);
	cout << b << endl;
	return 0;
}