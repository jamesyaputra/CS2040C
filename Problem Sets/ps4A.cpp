#include <iostream>
#include <map>
using namespace std;

map <string, int> babies;
int main () {
	int operation, gender, count;
	string name, lower, upper;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> operation, operation) {
		if (operation == 1) {
			cin >> name >> gender;
			babies[name] = gender;
		} else if (operation == 2) {
			cin >> name;
			babies.erase(name);
		} else {
			count = 0;
			cin >> lower >> upper >> gender;
			for (auto it = babies.begin(); it != babies.end(); it++) {
				if (!gender && lower <= it->first && it->first < upper) {
				count++;
				} else if (it->second == gender && lower <= it->first && it->first < upper) count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}