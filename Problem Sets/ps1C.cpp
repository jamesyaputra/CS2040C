#include <iostream>
#include <queue>
using namespace std;

int main () {
	int numCases, num;
	long sum, x;
	priority_queue <long, vector<long>, greater<long> > q2;
	priority_queue <long> q1;
	
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		cin >> num;
		sum = 0;
		q2 = priority_queue <long, vector<long>, greater<long> > ();
		q1 = priority_queue <long> ();
		for (int j = 0; j < num; j++) {
			cin >> x;
			if (q2.empty()) 		q2.push(x);
			else if (x < q2.top())	q1.push(x);
			else if (x >= q2.top())	q2.push(x);
			else if (j == 1) {
				q2.push(x);
				q1.push(q2.top());
				q2.pop();
			}
			
			if (q1.size() > q2.size()) {
				q2.push(q1.top());
				q1.pop();
			} else if (q2.size() == q1.size()+2) {
				q1.push(q2.top());
				q2.pop();
			}
			
			if (j%2) sum += (q1.top()+q2.top())/2;
			else 	 sum += q2.top();
		}
		cout << sum << endl;
	}
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl; 
	return 0;
}