#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void merge (long long int *a, int low, int high, int mid) {
	long long int temp[high-low+1];
	int i, j, k;
	i = low;
	j = mid+1;
	k = 0;

	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			i++;
			k++;
		} else {
			temp[k] = a[j];
			j++;
			k++;
		}
	}

	while (i <= mid) {
		temp[k] = a[i];
		i++;
		k++;
	}

	while (j <= high) {
		temp[k] = a[j];
		j++;
		k++;
	}

	for (i = low; i <= high; i++) {
		a[i] = temp[i-low];
	}
}

void mergeSort (long long int *a, int low, int high) {
	int mid;

	if (low < high) {
		mid = (high+low)/2;

		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);

		merge(a, low, high, mid);
	}
}

int main () {
	int num, i;
	time_t start, end;

	//cout << "Enter number of elements to be sorted: ";
	//cin >> num;
	num = 300000;
	long long int arr[num], lower, upper;
	
	/*cout << "Enter lower bound (inclusive): ";
	cin >> lower;
	cout << "Enter upper bound (non-inclusive): ";
	cin >>upper;*/
	upper = 1000;
	lower = 0;
	
	srand(time(NULL));

	for (i = 0; i < num; i++) {
		arr[i] = (rand()%upper) + lower;
	}
	
	start = clock();
	mergeSort(arr, 0, num-1);
	end = clock();

	cout << "Sorted data: " << endl;
	for (i = 0; i < num; i++) cout << arr[i] << " ";
	cout << endl;
	cout << "Execution time: " << (double)(end-start)/CLOCKS_PER_SEC << endl;
	return 0;
}
