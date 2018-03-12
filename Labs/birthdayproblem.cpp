#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main () {
	vector <tuple<int, int, int> > vect;
	int num, a, b, c;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> a >> b >> c;
		c = 0 - c;
		vect.push_back(make_tuple(b, a, c));
	}

	sort(vect.begin(), vect.end());

	cout << endl;
	for (auto &p: vect)
		printf("%d %d %d\n", get<1>(p), get<0>(p), -get<2>(p));

	return 0;
}
