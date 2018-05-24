#include <iostream>
#include <vector>
using namespace std;

int main () {
	vector<int> v;
	int z;

	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	}

	cin >> z;
	
	int x = 0;
	for (int y = (int)v.size()-1; y >= 0; y--) {
		while (v[x] + v[y] < z && x + 1 < y) x++;
		if (v[x] + v[y] == z) {
			cout << "FOUND -> " << v[x] << " " << v[y] << endl;
			break;
		}
	}

	return 0;
}