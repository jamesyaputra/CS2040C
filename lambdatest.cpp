#include <iostream>
#include <vector>
using namespace std;

int main () {
	long num, x;
	vector <long> vect;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x;
		vect.push_back(x);
	}

	sort(vect.begin(), vect.end(), [](long a, long b) {return a > b;});

	for (int i = 0; i < num; i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
	return 0;
}