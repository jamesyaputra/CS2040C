//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <long int> vect;
	long int numTest, num, x, sum;
	int k;

	cin >> numTest;

	for (int i = 0; i < numTest; i++) {
		vect.clear();
		cin >> num;
		sum = 0;
		for (int j = 0; j < num; j++) {
			cin >> x;
			if (vect.size() == 0) {
				vect.push_back(x);
			} else {
				for (k = vect.size()-1; k >= 0; k--)
					if (vect[k] <= x) break;
				vect.insert(vect.begin()+k+1, x);
			}
			if (j%2) sum += (vect[j/2]+vect[(j/2)+1])/2;
			else sum += vect[j/2];
		}
		cout << sum << endl;
	}

	return 0;
}