#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main () {
	vector<int> v;
	string in, out;

	getline(cin, in);
	istringstream iss(in);
	while (iss >> out) {
		int size = sizeof(out);
		if (out[size-1] == ',') out.pop_back();
		v.push_back(stoi(out));
	}

	for (auto &it : v)
		cout << it << " ";
	cout << endl;

	return 0;
}