#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[1000001];

long long init(int a[], vector<long long>& t, long long node, long long start, long long end)
{
	if (start == end)
		return t[node] = a[start];
	return t[node] = init(a, t, node * 2, start, (start + end) / 2) + init(a, t, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(vector<long long>& t, long long node, long long start, long long end, long long left, long long right)
{
	if (left > end || right < start)
		return 0;
	if (start >= left && end <= right)
		return t[node];
	return sum(t, node * 2, start, (start + end) / 2, left, right) + sum(t, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& t, long long index, long long node, long long start, long long end, long long diff)
{
	if (index > end || index < start) return;
	t[node] += diff;
	if (start != end) {
		update(t, index, node * 2, start, (start + end) / 2, diff);
		update(t, index, node * 2 + 1, (start + end) / 2 + 1, end, diff);
	}
}

void showtree(vector<long long>& t, long long ts)
{
	for (long long i = 1; i < ts; i++)
	{
		cout << t[i] << ' ';
	}
	cout << '\n';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, k, a, b, c;
	cin >> n>>m>>k;

	long long h = (long long)ceil(log2(n));
	long long tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (long long i = 1; i <= n; i++)
		cin >> arr[i];
	
	init(arr, tree, 1, 1, n);
	for (long long i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long diff = c- arr[b];
			arr[b] = c;
			update(tree, b, 1, 1, n, diff);
		}
		else {
			cout << sum(tree, 1, 1, n, b, c) << '\n';
		}
	}

	return 0;
}