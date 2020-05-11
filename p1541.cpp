#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a;
void sum(int idx) {
	int n, temp = idx, pVal, startIdx;
	while (temp > 0 && isdigit(a[temp-1]))
		temp--;

	n = stoi(a.substr(temp, idx));
	startIdx = temp;

	temp = idx + 1;
	idx++;
	while (true) {
		while (temp < a.length() && isdigit(a[temp]))
			temp++;

		pVal = stoi(a.substr(idx, temp));
		n += pVal;

		if (temp < a.length() && a[temp] == '+') {
			idx = temp + 1;
			temp = idx + 1;
		}
		else {
			break;
		}
	}

	a.erase(a.begin() + startIdx, a.begin() + temp);
	a.insert(startIdx, to_string(n));
}

int subtract() {
	int n, idx, temp = 0, pVal;

	idx = a.find('-');
	if (idx != -1) {
		n = stoi(a.substr(temp, idx));

		idx++;
		while (true) {
			temp = a.find('-', idx);
			if (temp == -1) {
				pVal = stoi(a.substr(idx, a.length() - idx));
				n -= pVal;
				break;
			}
			else {
				pVal = stoi(a.substr(idx, temp));
				n -= pVal;

				idx = temp + 1;
			}

			
		}
	}
	else {
		n = stoi(a);
	}
	
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> a;

	int idx = a.find('+');
	while (idx != -1) {
		sum(idx);
		idx = a.find('+');
	}

	cout << subtract() << '\n';
	return 0;
}