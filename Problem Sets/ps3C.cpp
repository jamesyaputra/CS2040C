#include <iostream>
#include <map>
#include <tuple>
#include <set>
using namespace std;

map<string, pair<int, int> > dataset;
set<tuple<int, int, string> > q;
volatile int arrived = -1;

void arrive(string name, int dilation) {
	dataset.insert(make_pair(name, make_pair(dilation, arrived)));
	q.insert(make_tuple(dilation, arrived, name));
	arrived--;
}

void update(string name, int dilation) {
	auto itMap = dataset.find(name);
	auto itSet = q.find(make_tuple((*itMap).second.first, (*itMap).second.second, (*itMap).first));
	int temp = get<0>(*itSet) + dilation;
	int temp1 = get<1>(*itSet);
	q.erase(itSet);
	dataset.erase(itMap);
	q.insert(make_tuple(temp, temp1, name));
	dataset.insert(make_pair(name, make_pair(temp, temp1)));
}

void birth(string name) {
	auto itMap = dataset.find(name);
	auto itSet = q.find(make_tuple((*itMap).second.first, (*itMap).second.second, (*itMap).first));
	q.erase(itSet);
	dataset.erase(itMap);
}

string query() {
	if (dataset.empty()) return "The delivery suite is empty";
	auto it = q.end();
	it--;
	return get<2>(*it);
}

int main() {
	int cmd, dilation, test;
	string name;
	cin >> test;
	while (test--) {
		cin >> cmd;
		if (!cmd) {
			cin >> name >> dilation;
			arrive(name, dilation);
		} else if (cmd == 1) {
			cin >> name >> dilation;
			update(name, dilation);
		} else if (cmd == 2) {
			cin >> name;
			birth(name);
		} else {
			cout << query() << endl;
		}
	}
	return 0;
}