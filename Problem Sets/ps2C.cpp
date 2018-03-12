#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main () {
	int num, type, val;
	int isQ, isPQ, isST, run;
	queue<int> q1;
	priority_queue<int> p1;
	stack<int> s1;

	while (1) {
		cin >> num;
		if (num == 0) break;
		isQ = isPQ = isST = 0;
		run = 0;
		q1 = queue <int> ();
		p1 = priority_queue <int> ();
		s1 = stack <int> ();
		for (int i = 0; i < num; i++) {
			cin >> type >> val;

			if (type == 1) {
				q1.push(val);
				p1.push(val);
				s1.push(val);
			} else if (!q1.empty() && !s1.empty() && !p1.empty()){
				if (q1.front() == val) {
					if (run == 0) {
						isQ = 1;
					}
				} else {
					isQ = 0;
				}

				if (s1.top() == val) {
					if (run == 0) {
						isST = 1;
					}
				} else {
					isST = 0;
				}

				if (p1.top() == val) {
					if (run == 0) {
						isPQ = 1;
					}
				} else {
					isPQ = 0;
				}
				run = 1;
				q1.pop();
				s1.pop();
				p1.pop();
			}
		}
		if (isQ + isPQ + isST > 1) cout << "not sure" << endl;
		else if (isQ + isPQ + isST == 0) cout << "impossible" << endl;
		else if (isQ == 1) cout << "queue" << endl;
		else if (isPQ == 1) cout << "priority queue" << endl;
		else cout << "stack" << endl;
	}
	return 0;
}
