#include <iostream>
#include <list>
#include <string>
using namespace std;

int main () {
	char input;
	string str;
	list <char> l1;
	list<char>::iterator it;

	while (getline(cin, str)) {
		it = l1.begin(); //do not forget to reinitialize iterator in every iteration
		for (int i = 0; i < str.size(); i++) {
			input = str[i];
			if (input == '[') {
				it = l1.begin();
			} else if (input == ']') {
				it = l1.end();
			} else {
				l1.insert(it, input);
			}
		}

		while (!l1.empty()) {
			cout << l1.front();
			l1.pop_front();
		}
		cout << endl;
	}
	return 0;
}