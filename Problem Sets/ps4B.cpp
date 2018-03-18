#include <iostream>
#include <map>
#include <set>
using namespace std;

map<char, set<string> > boy, girl;
int main () {
	int operation, gender, count;
	string name, lower, upper;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> operation, operation) {
		if (operation == 1) {
			cin >> name >> gender;
			if (gender == 1) boy[name[0]].insert(name);
			else girl[name[0]].insert(name);
		} else if (operation == 2) {
			cin >> name;
			if (boy[name[0]].find(name) == boy[name[0]].end()) girl[name[0]].erase(name);
			else boy[name[0]].erase(name);
		} else {
			count = 0;
			cin >> lower >> upper >> gender;

			if (!gender) {
				if (lower[0] == upper[0]) {
					for (auto it = boy[lower[0]].lower_bound(lower); it != boy[lower[0]].upper_bound(upper); it++) count++;
					for (auto it = girl[lower[0]].lower_bound(lower); it != girl[lower[0]].upper_bound(upper); it++) count++;
				} else {
					for (auto it = boy[lower[0]].lower_bound(lower); it != boy[lower[0]].end(); it++) count++;
					for (char i = (lower[0])+1; i < upper[0]; i++) count += (int)boy[i].size();
					for (auto it = boy[upper[0]].begin(); it != boy[upper[0]].upper_bound(upper); it++)	count++;
					for (auto it = girl[lower[0]].lower_bound(lower); it != girl[lower[0]].end(); it++) count++;
					for (char i = (lower[0])+1; i < upper[0]; i++) count += (int)girl[i].size();
					for (auto it = girl[upper[0]].begin(); it != girl[upper[0]].upper_bound(upper); it++) count++;		
				}
				if (boy[upper[0]].find(upper) != boy[upper[0]].end()) count--;
				if (girl[upper[0]].find(upper) != girl[upper[0]].end()) count--;
			} else if (gender == 1) {
				if (lower[0] == upper[0]) {
					for (auto it = boy[lower[0]].lower_bound(lower); it != boy[lower[0]].upper_bound(upper); it++) count++;
				} else {
					for (auto it = boy[lower[0]].lower_bound(lower); it != boy[lower[0]].end(); it++) count++;
					for (char i = (lower[0])+1; i < upper[0]; i++) count += (int)boy[i].size();
					for (auto it = boy[upper[0]].begin(); it != boy[upper[0]].upper_bound(upper); it++)	count++;			
				}
				if (boy[upper[0]].find(upper) != boy[upper[0]].end()) count--;
			} else {
				if (lower[0] == upper[0]) {
					for (auto it = girl[lower[0]].lower_bound(lower); it != girl[lower[0]].upper_bound(upper); it++) count++;
				} else {
					for (auto it = girl[lower[0]].lower_bound(lower); it != girl[lower[0]].end(); it++) count++;
					for (char i = (lower[0])+1; i < upper[0]; i++) count += (int)girl[i].size();
					for (auto it = girl[upper[0]].begin(); it != girl[upper[0]].upper_bound(upper); it++) count++;		
				}
				if (girl[upper[0]].find(upper) != girl[upper[0]].end()) count--;
			}
			cout << count << endl;
		}
	}
	return 0;
}