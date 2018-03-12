#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	node *prev;
	node *next;
};

class deque {
private:
	node *head;
	node *tail;
	int size;
public:
	deque () {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	deque (vector<int> vect) {
		size = 0;
		while (!vect.empty()) {
			create(vect.back());
			vect.pop_back();
		}
	}

	void create (int value) {
		node *temp = new node;
		temp->data = value;

		if (size == 0) {
			temp->prev = NULL;
			temp->next = NULL;
			head = temp;
			tail = temp;
		} else {
			temp->prev = tail;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	int front () {
		if (head == NULL) return -1;
		return head->data;
	}

	int back () {
		if (tail == NULL) return -1;
		return tail->data;
	}

	void displayHead () {
		node *cur = new node;
		cur = head;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	void displayTail () {
		node *cur = new node;
		cur = tail;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->prev;
		}
		cout << endl;
	}

	void push_front (int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
		size++;
	}

	void push_back (int value) {
		node *temp = new node;
		temp->data = value;
		temp->prev = tail;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		size++;
	}

	void pop_front () {
		if (size == 0) return;
		node *temp = new node;
		temp = head;
		head = temp->next;;
		head->prev = NULL;
		temp->next = NULL;
		size--;
		delete temp;
	}

	void pop_back () {
		if (size == 0) return;
		node *temp = new node;
		temp = tail;
		tail = temp->prev;
		tail->next = NULL;
		temp->prev = NULL;
		size--;
		delete temp;
	}
};

int main () {
	vector <int> vect ({1,2,3,4,5,6,7,8,9,10});
	deque list(vect);
	list.displayTail();
	list.displayHead();
	return 0;
}