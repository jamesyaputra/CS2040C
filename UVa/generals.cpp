#include <iostream>
#include <vector>
using namespace std;

int main () {
	int troops, groups;
	int left, right;
	vector<int> vect;
	cin >> troops >> groups;
	
	for (int i = 0; i < troops; i++) {
		vect.push_back(i);
	}

	for (int i = 0; i < groups; i++) {
		cin >> left >> right;
		int l, r, run = 0;

		for (int j = 0; vect[j] <= left && j < vect.size(); j++) {
			if (vect[j] == left) {
				if (j+(right-left)+1 < vect.size()) r = vect[j+(right-left)+1];
				else r = -1;

				if (j-1 >= 0) l = vect[j-1];
				else l = -1;
				cout << l << " " << r << endl;

				if (right-left == 0) vect.erase(vect.begin()+j);
				else {
					auto it = vect.begin()+j;
					while (*it != right) {
						vect.erase(it);
						run = 1;
					}
					if (run) {
						vect.erase(it);
					}
				}
			}
		}
	}
	return 0;
}