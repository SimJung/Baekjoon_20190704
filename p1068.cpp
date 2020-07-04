#include <iostream>
#include <vector>
#include <algorithm>
#define pi pair<int, int>
using namespace std;

int nodeNum;
int delNode;

class Tree {
private:
	int val;
	vector<Tree*> children;
public:
	Tree(int v) : val(v) {
		children.clear();
	}

	bool isLeaf() {
		return children.empty();
	}

	int getLeafNum() {
		if (val == delNode)
			return 0;

		if (isLeaf() || (children.size() == 1 && children[0]->getVal() == delNode))
			return 1;
		else {
			int sum = 0;
			for (int i = 0; i < children.size(); i++) {
				sum += children[i]->getLeafNum();
			}
			return sum;
		}
	}

	int getVal() {
		return val;
	}

	void pushChild(Tree* t) {
		children.push_back(t);
	}
};

vector<Tree> v;
int arr[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodeNum;

	for (int i = 0; i < nodeNum; i++) {
		cin >> arr[i];
		Tree t(i);
		v.push_back(t);
	}
	Tree* head = NULL;
	for (int i = 0; i < nodeNum; i++) {
		if (arr[i] == -1) {
			head = &v[i];
			continue;
		}

		for (int j = 0; j < nodeNum; j++) {
			if (v[j].getVal() == arr[i]) {
				v[j].pushChild(&v[i]);
			}
		}
	}
	cin >> delNode;
	
	cout << head->getLeafNum() << '\n';

	return 0;
}