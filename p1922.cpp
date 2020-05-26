#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Road;

//���� ������ ��� Ŭ����. ���� ��ȣ, ���ø�, ������ �α�, ����� ����Ʈ ���� ����.
class City {
private:
	int id;
	string name;
	int population;
	City* parent;
	City* tail;
	int cntCity;
	Road* cRoad;

public:
	City(int i, string n, int p, City* ptr_p, City* ptr_t) : id(i), name(n), population(p), parent(ptr_p), tail(ptr_t) { cntCity = 1; cRoad = NULL; }
	void setId(int n) { id = n; }
	int getId() { return id; }

	void setName(string s) { name = s; }
	string getName() { return name; }

	void setPopulation(int p) { population = p; }
	int getPopulation() { return population; }

	City* setParent(City* ptr) { parent = ptr; return parent; }
	City* getParent() { return parent; }

	void setTail(City* ptr) { tail = ptr; }
	City* getTail() { return tail; }

	void setCntCity(int n) { cntCity = n; }
	int getCntCity() { return cntCity; }

	void setCRoad(Road* ptr) { cRoad = ptr; }
	Road* getCRoad() { return cRoad; }

	void pushCity(City* ptr);

	void pushRoad(Road* ptr);

	int roadCost();
};

//�����嵵���� ������ ��� Ŭ����. ������, ������, ��� ���� �ִ�.
//�� �պ� �����̱� ������ ��ǻ� ����׷����̴�.
class Road {
private:
	City* from;
	City* to;
	int cost;
	Road* next;

public:
	Road(int c) : cost(c) {
		from = NULL;
		to = NULL;
		next = NULL;
	}
	void setFrom(City* ptr) { from = ptr; }
	City* getFrom() { return from; }

	void setTo(City* ptr) { to = ptr; }
	City* getTo() { return to; }

	void setCost(int n) { cost = n; }
	int getCost() { return cost; }

	void setNext(Road* ptr) { next = ptr; }
	Road* getNext() { return next; }
};

void City::pushCity(City* ptr) {
	if (tail == NULL) {
		setTail(ptr);
	}
	else {
		City* temp = tail;
		while (temp->getTail() != NULL)
			temp = temp->getTail();
		temp->setTail(ptr);
	}
}

void City::pushRoad(Road* ptr) {
	if (cRoad == NULL) {
		setCRoad(ptr);
	}
	else {
		Road* temp = cRoad;
		while (temp->getNext() != NULL)
			temp = temp->getNext();
		temp->setNext(ptr);
	}
}

int City::roadCost() {
	int sum = 0;
	Road* temp = cRoad;
	while (temp->getNext() != NULL) {
		sum += temp->getCost();
		temp = temp->getNext();
	}
	return sum + temp->getCost();
}

int n, m, q; //n : ���õ��� ����, m: �����嵵���� ����, q: ������ ��
vector<City> vector_City; //���� ������ �����ϴ� vector
vector<Road> vector_Road; //�����嵵�� ������ �����ϴ� vector

// City vector�� ������ �� ���� compare �Լ�.
bool cmpCity(City a, City b) {
	return a.getId() < b.getId();
}

// Road vector�� ������ �� ���� compare �Լ�.
bool cmpRoad(Road a, Road b) {
	//1�������� cost�� ���Ѵ�.
	if (a.getCost() != b.getCost())
		return a.getCost() < b.getCost();

	//cost�� ���ٸ� �� �� �α����� ���� ���Ѵ�.
	int apop = a.getFrom()->getPopulation() + a.getTo()->getPopulation();
	int bpop = b.getFrom()->getPopulation() + b.getTo()->getPopulation();
	if (apop != bpop)
		return apop < bpop;

	//�α����� �յ� ���ٸ� �� ���� ��ȣ�� �����ϴ� ���� �켱���� �Ѵ�.
	int anum = a.getFrom()->getId() > a.getTo()->getId() ? a.getTo()->getId() : a.getFrom()->getId();
	int bnum = b.getFrom()->getId() > b.getTo()->getId() ? b.getTo()->getId() : b.getFrom()->getId();
	return anum < bnum;
}

// Union-Find���� find����, �ش� ���ð� ���� ������ ã�� �����̴�.
City* findCity(City* c) {
	if (c->getParent() == NULL)
		return c;
	return c->setParent(findCity(c->getParent()));
}

City* unionCity(City* a, City* b) {
	City* aHead = findCity(a);	//a���ð� ���� ����
	City* bHead = findCity(b);	//b���ð� ���� ����

	// a���ÿ� b������ ũ�Ⱑ ���� ���� ���
	if (aHead->getCntCity() != bHead->getCntCity()) {
		if (aHead->getCntCity() > bHead->getCntCity()) {
			aHead->setCntCity(aHead->getCntCity() + bHead->getCntCity());
			bHead->setCntCity(1);

			aHead->pushCity(bHead);
			aHead->pushRoad(bHead->getCRoad());
			bHead->setCRoad(NULL);

			bHead->setParent(aHead);
			return aHead;
		}
		else {
			bHead->setCntCity(aHead->getCntCity() + bHead->getCntCity());
			aHead->setCntCity(1);

			bHead->pushCity(aHead);
			bHead->pushRoad(aHead->getCRoad());
			aHead->setCRoad(NULL);

			aHead->setParent(bHead);
			return bHead;
		}
	}

	// a���ÿ� b������ ũ�Ⱑ ���� ���(leader id��)
	else {
		if (aHead->getId() < bHead->getId()) {
			aHead->setCntCity(aHead->getCntCity() + bHead->getCntCity());
			bHead->setCntCity(1);

			aHead->pushCity(bHead);
			aHead->pushRoad(bHead->getCRoad());
			bHead->setCRoad(NULL);

			bHead->setParent(aHead);

			return aHead;
		}
		else {
			bHead->setCntCity(aHead->getCntCity() + bHead->getCntCity());
			aHead->setCntCity(1);

			bHead->pushCity(aHead);
			bHead->pushRoad(aHead->getCRoad());
			aHead->setCRoad(NULL);

			aHead->setParent(bHead);
			return bHead;
		}
	}
}

//�ش� ��ȣ�� ���� ���ø� ã������ ����Ž�� �Լ�.
City* bSearch(int val) {
	int l = 0;
	int r = vector_City.size();
	int mid;

	while (l <= r) {
		mid = (l + r) / 2;
		if (val > vector_City[mid].getId())
			l = mid + 1;
		else if (val < vector_City[mid].getId())
			r = mid - 1;
		else
			return &vector_City[mid];
	}
	return NULL;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//������ ������ �Է¹޴� ����.
	int city_num, city_pop;
	string city_name;
	City temp_city(0, "", 0, NULL, NULL);
	for (int i = 0; i < n; i++) {
		city_num = i + 1;
		city_name = "city";
		city_pop = 10;

		//�Է¹��� �����͸� �������� City��ü�� vector�� �߰�.
		temp_city.setId(city_num);
		temp_city.setName(city_name);
		temp_city.setPopulation(city_pop);
		vector_City.push_back(temp_city);
	}
	//�Է¹��� ���õ��� ���� ��ȣ�� ���� ����
	sort(vector_City.begin(), vector_City.end(), cmpCity);

	//�����嵵���� ������ �Է¹޴� ����
	int road_from, road_to, road_cost;
	Road temp_road(0);
	for (int i = 0; i < m; i++) {
		cin >> road_from >> road_to >> road_cost;

		//�Է¹��� �����͸� �������� Road��ü�� vector�� �߰�
		temp_road.setFrom(bSearch(road_from));
		temp_road.setTo(bSearch(road_to));
		temp_road.setCost(road_cost);
		vector_Road.push_back(temp_road);
	}

	// �Է¹��� �����嵵�ε��� ���ؿ� ���� ����
	sort(vector_Road.begin(), vector_Road.end(), cmpRoad);

	//������ �Է¹޴� ����
	char command;
	City* temp = NULL;
	City* temp2 = NULL;
	City* uniRes = NULL;
	int p1, p2, curIdx = 0;
	bool result;
			while (true) {
				temp = findCity(vector_Road[curIdx].getFrom());
				temp2 = findCity(vector_Road[curIdx].getTo());

				if (temp->getId() != temp2->getId()) {
					uniRes = unionCity(temp, temp2);
					uniRes->pushRoad(&vector_Road[curIdx]);
					if (uniRes->getCntCity() == n) {
						cout << uniRes->roadCost() << '\n';
						return 0;
					}
				}
				curIdx++;
			}

	return 0;
}