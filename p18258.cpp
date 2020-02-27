#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Queue {
private:
	vector<int> arr;
	int start;
	int end;

public:
	Queue() : start(0), end(0) {}
	void push(int n) {
		arr.push_back(n);
		end++;
	}

	int size() {
		return end - start;
	}

	bool empty() {
		return (size() == 0);
	}

	int pop() {
		if (size())
			return arr[start++];
		else
			return -1;
	}

	int front() {
		if (size())
			return arr[start];
		else
			return -1;
	}

	int back() {
		if (size())
			return arr[end-1];
		else
			return -1;
	}
	
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	Queue q;
	string s;

	while (t--)
	{
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;

			q.push(n);
		}
		else if (s == "pop") {
			cout<<q.pop()<<'\n';
		}
		else if (s == "size") {
			cout<<q.size()<<'\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			cout << q.front() << '\n';
		}
		else if (s == "back") {
			cout << q.back() << '\n';
		}
	}
	return 0;
}