#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int main () {
	int set1[MAX], set2[MAX];
	int num1, num2;
	vector <int>::iterator it;

	cin >> num1 >> num2;
	vector <int> vect(10);

	for (int i = 0; i < num1; i++) {
		cin >> set1[i];
	}

	for (int i = 0; i < num2; i++) {
		cin >> set2[i];
	}

	sort(set1, set1+num1);
	sort(set2, set2+num2);

	it = set_intersection(set1, set1+num1, set2, set2+num2, vect.begin());
	vect.resize(it-vect.begin());

	cout << vect.size() << " elements" << endl;

	for (it = vect.begin(); it != vect.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}