#include <iostream>
#include <vector>
#define num 5
using namespace std;

int main(int argc, char const *argv[]) {
	int arr[num] = {1000, 78, -91, 45, 0};
	vector <int> second (arr, arr + num);

	for (int i = 0; i < num; i++) {
		cout << second[i] << endl;
	}

	cout << endl << sizeof(arr) << endl << sizeof(int) << endl;
	return 0;
}