#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, string> dataset;
vector<dataset> vect;
volatile int arrived = -1;

void birth(string name) {
	for (int i = 0; i < vect.size(); i++) if (get<2>(vect[i]) == name) {
		vect.erase(vect.begin()+i);
		break;
	}
}

void update(string name, int dilation) {
	dataset temp;
	for (int i = 0; i < vect.size(); i++) {
		if (get<2>(vect[i]) == name) {
			temp = vect[i];
			vect.erase(vect.begin()+i);
			vect.push_back(make_tuple(get<0>(temp) + dilation, get<1>(temp), name));
			break;
		}
	}
	stable_sort(vect.begin(), vect.end());
}

void arrive(string name, int dilation) {
	vect.push_back(make_tuple(dilation, arrived, name));
	arrived--;
	stable_sort(vect.begin(), vect.end());
}

string query() {
	if (!vect.empty()) return get<2>(vect.back());
	else return "The delivery suite is empty";
}

int main () {
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