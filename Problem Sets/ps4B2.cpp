#include <iostream>
#include <set>
using namespace std;

set <string> boy, girl;
int main () {
	int operation, count, gender;
	string name, lower, upper;

	while (cin >> operation, operation) {
		if (operation == 1) {
			cin >> name >> gender;
			if (gender == 1) boy.insert(name);
			else girl.insert(name);
		} else if (operation == 2) {
			cin >> name;
			if (boy.find(name) == boy.end()) girl.erase(name);
			else boy.erase(name);
		} else {
			count = 0;
			cin >> lower >> upper >> gender;
			if (!gender || gender == 1) {
				auto low = boy.lower_bound(lower);
				auto high = boy.upper_bound(upper);
				count += distance(low, high);
			} 
			if (!gender || gender == 2) {
				auto low1 = girl.lower_bound(lower);
				auto high1 = girl.upper_bound(upper);
				count += distance(low1, high1); 
			}
			cout << count << endl;
		}
	}
	return 0;
}