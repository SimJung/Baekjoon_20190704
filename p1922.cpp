#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Road;

//도시 정보를 담는 클래스. 도시 번호, 도시명, 도시의 인구, 연결된 리스트 등이 있음.
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

//비포장도로의 정보를 담는 클래스. 시작점, 도착점, 비용 등이 있다.
//단 왕복 도로이기 때문에 사실상 무향그래프이다.
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

int n, m, q; //n : 도시들의 개수, m: 비포장도로의 개수, q: 질의의 수
vector<City> vector_City; //도시 정보를 저장하는 vector
vector<Road> vector_Road; //비포장도로 정보를 저장하는 vector

// City vector를 정렬할 때 쓰일 compare 함수.
bool cmpCity(City a, City b) {
	return a.getId() < b.getId();
}

// Road vector를 정렬할 때 쓰일 compare 함수.
bool cmpRoad(Road a, Road b) {
	//1차적으로 cost를 비교한다.
	if (a.getCost() != b.getCost())
		return a.getCost() < b.getCost();

	//cost가 같다면 양 끝 인구수의 합을 비교한다.
	int apop = a.getFrom()->getPopulation() + a.getTo()->getPopulation();
	int bpop = b.getFrom()->getPopulation() + b.getTo()->getPopulation();
	if (apop != bpop)
		return apop < bpop;

	//인구수의 합도 같다면 더 작은 번호를 포함하는 곳을 우선으로 한다.
	int anum = a.getFrom()->getId() > a.getTo()->getId() ? a.getTo()->getId() : a.getFrom()->getId();
	int bnum = b.getFrom()->getId() > b.getTo()->getId() ? b.getTo()->getId() : b.getFrom()->getId();
	return anum < bnum;
}

// Union-Find에서 find연산, 해당 도시가 속한 집합을 찾는 연산이다.
City* findCity(City* c) {
	if (c->getParent() == NULL)
		return c;
	return c->setParent(findCity(c->getParent()));
}

City* unionCity(City* a, City* b) {
	City* aHead = findCity(a);	//a도시가 속한 집합
	City* bHead = findCity(b);	//b도시가 속한 집합

	// a도시와 b도시의 크기가 같지 않을 경우
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

	// a도시와 b도시의 크기가 같을 경우(leader id비교)
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

//해당 번호를 가진 도시를 찾기위한 이진탐색 함수.
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

	//도시의 정보를 입력받는 구간.
	int city_num, city_pop;
	string city_name;
	City temp_city(0, "", 0, NULL, NULL);
	for (int i = 0; i < n; i++) {
		city_num = i + 1;
		city_name = "city";
		city_pop = 10;

		//입력받은 데이터를 바탕으로 City객체를 vector에 추가.
		temp_city.setId(city_num);
		temp_city.setName(city_name);
		temp_city.setPopulation(city_pop);
		vector_City.push_back(temp_city);
	}
	//입력받은 도시들을 기준 번호에 따라 정렬
	sort(vector_City.begin(), vector_City.end(), cmpCity);

	//비포장도로의 정보를 입력받는 구간
	int road_from, road_to, road_cost;
	Road temp_road(0);
	for (int i = 0; i < m; i++) {
		cin >> road_from >> road_to >> road_cost;

		//입력받은 데이터를 바탕으로 Road객체를 vector에 추가
		temp_road.setFrom(bSearch(road_from));
		temp_road.setTo(bSearch(road_to));
		temp_road.setCost(road_cost);
		vector_Road.push_back(temp_road);
	}

	// 입력받은 비포장도로들을 기준에 따라 정렬
	sort(vector_Road.begin(), vector_Road.end(), cmpRoad);

	//쿼리를 입력받는 구간
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