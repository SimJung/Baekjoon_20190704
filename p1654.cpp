#include <iostream>
using namespace std;

long long int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int cnt=0, n, k, l=0, r=0, m;
	cin >> n>>k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r += arr[i];
	}


	
	while (l < r) {
		cnt = 0;
		m = (l + r) / 2;
		if (m == 0){
			m++;
			break;
		}

		for (int i = 0; i < n; i++) {
			cnt += arr[i] / m;
			if (arr[i] < m)
			{
				cnt = 0;
				break;
			}
		}

		// �ʹ� ���!
		if (cnt < k) {
			r = m - 1;
		}
		//�ʹ� ª��!
		else {
			l = m + 1;
		}
	}

	cout << m << '\n';
	return 0;
}