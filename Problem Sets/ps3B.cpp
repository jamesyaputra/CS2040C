#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, string> iis;
priority_queue<iis> prio;
volatile int arrived = -1;

void arrive(string name, int dilate) {
	prio.push(make_tuple(dilate, arrived, name));
	arrived--;
}

string query() {
	if (!prio.empty()) return get<2>(prio.top());
	return "The delivery suite is empty";
}

int main () {
	int cmd, dilate, test;
	string name;
	cin >> test;
	while (test--) {
		cin >> cmd;
		if (!cmd) {
			cin >> name >> dilate;
			arrive(name, dilate);
		} else if (cmd == 2) {
			cin >> name;
			prio.pop();
		} else {
			cout << query() << endl;
		}
	}
	return 0;
}