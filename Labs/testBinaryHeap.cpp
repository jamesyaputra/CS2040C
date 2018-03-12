#include <iostream>
#include <vector>
using namespace std;

class binaryHeap {
private:
	vector <int> heap;

	void maxHeap (int index) {
		int right = 2*index+2;
		int left = 2*index+1;

		//If right child exists, left child exists
        if (right < heap.size()) {
        	//Compares size of children
        	if (heap[right] > heap[left] && heap[right] > heap[index]) {
        		swap(heap[index], heap[right]);
        		maxHeap(right);
        	} else if (heap[left] > heap[index]) {
        		swap(heap[index], heap[left]);
        		maxHeap(left);
        	}
        //Checks if left child exists
        } else if (left < heap.size() && heap[left] > heap[index]) {
        	swap(heap[index], heap[left]);
        	maxHeap(left);
        }
    }

    void minHeap (int index) {
		int right = 2*index+2;
		int left = 2*index+1;

        if (right < heap.size()) {
        	if (heap[right] < heap[left] && heap[right] < heap[index]) {
        		swap(heap[index], heap[right]);
        		minHeap(right);
        	} else if (heap[left] < heap[index]) {
        		swap(heap[index], heap[left]);
        		minHeap(left);
        	}
        } else if (left < heap.size() && heap[left] < heap[index]) {
        	swap(heap[index], heap[left]);
        	minHeap(left);
        }
    }

	void shiftMax (int index) {
		if (heap[index] > heap[(index-1)/2]) {
			swap(heap[index], heap[(index-1)/2]);
			shiftMax((index-1)/2);
		}
	}

	void shiftMin (int index) {
		if (heap[index] < heap[(index-1)/2]) {
			swap(heap[index], heap[(index-1)/2]);
			shiftMin((index-1)/2);
		}
	}
public:
	binaryHeap () {}
	binaryHeap (vector<int> vect, int det) {
		if (det) build(vect);
		else buildMin(vect);
	}

	void build (vector<int> vect) {
		heap = vect;
		for (int i = heap.size()/2; i >= 0; i--) {
			maxHeap(i);
		}
	}

	void buildMin (vector<int> vect) {
		heap = vect;
		for (int i = heap.size()/2; i >= 0; i--) {
			minHeap(i);
		}
	}

	void build_slow (vector<int> vect) {
		vector<int>::iterator i;
		for (i = vect.begin(); i != vect.end(); i++) {
            push(*i);
        }
	}

	void build_slowMin (vector<int> vect) {
		vector<int>::iterator i;
		for (i = vect.begin(); i != vect.end(); i++) {
            pushMin(*i);
        }
	}

	void push (int value) {
		heap.push_back(value);
		shiftMax(heap.size()-1);
	}

	void pushMin (int value) {
		heap.push_back(value);
		shiftMin(heap.size()-1);
	}

	int root () {
		if (!heap.empty()) return heap[0];
		else return -1;
	}

	void pop_root () {
		swap(heap[0], heap[heap.size()-1]);
		heap.pop_back();
		if (heap.empty()) return;
		maxHeap(0);
	}

	void pop_rootMin() {
		swap(heap[0], heap[heap.size()-1]);
		heap.pop_back();
		if (heap.empty()) return;
		minHeap(0);
	}

	void heapSort (vector<int> *vect) {
		heap = *vect;
		int size = heap.size();
		build(heap);
		(*vect).clear();
		for (int i = 0; i < size; i++) {
			swap(heap[0], heap[heap.size()-1]);
			(*vect).push_back(heap.back());
			heap.pop_back();
			maxHeap(0);
		}
	}

	void heapSortMin (vector<int> *vect) {
		heap = *vect;
		int size = heap.size();
		buildMin(heap);
		(*vect).clear();
		for (int i = 0; i < size; i++) {
			swap(heap[0], heap[heap.size()-1]);
			(*vect).push_back(heap.back());
			heap.pop_back();
			minHeap(0);
		}
	}
};

int main () {
	//This vector constructor can only be used in C++11
	//vector <int> myVector({1,100,99,5, 12, 23, 65, 76, 900, 1231, 45});
	vector<int> myVector;
	time_t start, end;

	srand(time(NULL));
	for (int i = 0; i < 300000; i++) myVector.push_back(rand()%10001);
	//for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++) cout << *it << " ";
	
	binaryHeap bin = binaryHeap();
	start = clock();
	bin.heapSortMin(&myVector);
	end = clock();
	cout << "Heap Sort = ";
	for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++) cout << *it << " ";

	int x;
	bin.buildMin(myVector);
	cout << endl << "Check priority queue = ";
	for (int i = 0; i < myVector.size(); i++) {
		x = bin.root();
		cout << x << " ";
		bin.pop_rootMin();
	}
	cout << endl << (double)(end-start)/CLOCKS_PER_SEC << endl;
	return 0;
}