#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[1001];
int expand;

long long init(int a[], vector<long long> &t, int node, int start, int end)
{
	cout << node << ' ' << start << ' ' << end<<'\n';
	if (start == end)
	{
		return t[node] = a[start];
	}
		
	else
	{
		return t[node] = init(a, t, node * 2, start, (start + end) / 2) + init(a, t, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void show(vector<long long> tr, int tree_size)
{
	for (int i = 1; i < tree_size; i++)
	{
		cout << tr[i]<<' ';
	}
	cout << '\n';
}

long long sum(vector<long long>& t, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && right >= end)
		return t[node];
	return sum(t, node * 2, start, (start + end) / 2, left, right) + sum(t, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

long long update(vector<long long>& t, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;
	t[node] = t[node] + diff;
	if (start != end) {
		update(t, node * 2, start, (start + end) / 2, index, diff);
		update(t, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(void)
{
	cout << "구간 합의 범위를 정해줘 : ";
	cin >> expand;

	for (int i = 1; i <= expand; i++)
	{
		arr[i] = i;
	}

	int h = (int)ceil(log2(expand));
	int tree_size = (1 << (h + 1));
	cout << h<<'\n'<<tree_size << '\n';
	vector<long long> tr(tree_size);
	init(arr, tr, 1, 1, expand);

	show(tr, tree_size);
	return 0;
}