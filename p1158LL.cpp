#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
	Node* prev;

public:
	Node(int d, Node* n, Node* p) : data(d), next(n), prev(p)
	{
	}
	
	int getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}

	Node* getPrev()
	{
		return prev;
	}


	void setNext(Node* n)
	{
		next = n;
	}

	void setPrev(Node* n)
	{
		prev = n;
	}

	void setData(int d)
	{
		data = d;
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, d, num, now_d;
	
	cin >> t>>d;
	Node* head = new Node(d, 0, 0);

	Node* temp = head;

	num = t;
	now_d = d;

	while (t--)
	{
		now_d++;
		if (now_d > num)
		{
			now_d -= num;
		}

		if (now_d == d)
		{
			temp->setNext(head);
			head->setPrev(temp);
			temp = temp->getNext();
		}
		else
		{
			Node* new_node = new Node(now_d, 0, temp);
			temp->setNext(new_node);

			temp = temp->getNext();
		}
	}


	t = num;
	cout << '<';

	while (t--)
	{
		if (t)
			cout << temp->getData() << ", ";
		else
			cout << temp->getData();

		Node* delNode = temp;
		temp->getPrev()->setNext(temp->getNext());
		temp->getNext()->setPrev(temp->getPrev());

		for (int i = 0; i < d; i++)
		{
			temp = temp->getNext();
		}

		delete delNode;


	}

	cout << ">\n";

	return 0;
}