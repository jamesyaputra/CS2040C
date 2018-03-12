#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <long int> vect;
	long int numTest, num;
	long int x, sum;

	cin >> numTest;

	for (int i = 0; i < numTest; i++) {
		vect.clear();
		cin >> num;
		sum = 0;
		for (int j = 0; j < num; j++) {
			cin >> x;
			vect.push_back(x);
			sort(vect.begin(), vect.end());
			if (j%2) {
				sum += (vect[j/2]+vect[(j/2)+1])/2;
			} else {
				sum += vect[j/2];
			}
		}
		cout << sum << endl;
	}

	return 0;
}