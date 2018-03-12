#include <iostream>
using namespace std;

class binny {
private:
    int hoppity[100000];
    int size;

    void maxH (int index, int maximum) {
        int right = 2*index+2;
        int left = 2*index+1;

        //If right child exists, left child exists
        if (right < maximum) {
            //Compares size of children
            if (hoppity[right] > hoppity[left] && hoppity[right] > hoppity[index]) {
                swap(hoppity[index], hoppity[right]);
                maxH(right, maximum);
            } else if (hoppity[left] > hoppity[index]) {
                swap(hoppity[index], hoppity[left]);
                maxH(left, maximum);
            }
        //Checks if left child exists
        } else if (left < maximum && hoppity[left] > hoppity[index]) {
            swap(hoppity[index], hoppity[left]);
            maxH(left, maximum);
        }
    }

    void traverse (int i) {
        if (hoppity[i] > hoppity[(i-1)/2]) {
            swap(hoppity[i], hoppity[(i-1)/2]);
            traverse((i-1)/2);
        }
    }
public:
    binny() {
        size = 0;
    }
    
    void push(int value) {
        hoppity[size] = value;
        size++;
        traverse(size - 1);
    }

    void popRoot() {
        if (size == 0) return;
        swap(hoppity[0], hoppity[size - 1]);
        size--;
        maxH(0, size);
    }
     
    int root() {
        if (size == 0) return -101;
        return hoppity[0];
    }

    int binsize() {
        return size;
    }
};

int main () {
    int num,type, value, size, run = 0, index;
    int isQ, isP, isS;

    while (1) {
        cin >>num;
        if (num == 0) break;
        int s1[100000];
        binny *bunny = new binny;
        isQ = isP = isS = size = index = run = 0;
        for (int i = 0; i < num; i++) {
            cin >> type >> value;

            if (type == 1) {
                s1[size] = value;
                bunny->push(value);
                size++;
            } else if (size != 0 && bunny->binsize() != 0){
                if (value == s1[index]) {
                    if (run == 0) isQ = 1;
                } else isQ = 0;

                if (value == s1[size-1-index]) {
                    if (run == 0) isS = 1;
                } else isS = 0;

                if (value == bunny->root()) {
                    if (run == 0) isP = 1;
                } else isP = 0;

                run = 1;
                bunny->popRoot();
                index++;
            }
        }
        if (isQ + isP + isS > 1) cout << "not sure" << endl;
        else if (isQ + isP + isS == 0) cout << "impossible" << endl;
        else if (isQ == 1) cout << "queue" << endl;
        else if (isP == 1) cout << "priority queue" << endl;
        else cout << "stack" << endl;
    }
    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl; 
    return 0;
} 