#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	node *prev;
	node *next;
};

class LinkedList {
private:
	node *head;
	node *tail;
	int size;
public:
	LinkedList () {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	LinkedList (vector<int> vect) {
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

	int get (int pos) {
		if (pos < 0 || pos > size-1) return -1;
		node *cur = new node;
		cur = head;
		for (int i = 0; i < pos; i++) {
			cur = cur->next;

		}
		return cur->data;
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

	void insert (int pos, int value) {
		if (pos < 0 || pos > size-1) return;
		node *pre = new node;
		node *cur = new node;
		node *aft = new node;

		if (pos <= size/2) {
			cur = head;
			for (int i = 0; i < pos; i++) {
				pre = cur;
				cur = cur->next;
			}
		} else {
			cur = tail;
			for (int i = 0; i < size-pos-1; i++) {
				pre = cur;
				cur = cur->prev;
			}
		}
		aft->data = value;
		aft->prev = pre;
		aft->next = cur;
		cur->prev = aft;
		pre->next = aft;
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

	void pop_pos (int pos) {
		if (pos < 0 || pos > size-1 || size == 0) return;
		node *pre = new node;
		node *cur = new node;

		if (pos <= size/2) {
			cur = head;
			for (int i = 0; i < pos; i++) {
				pre = cur;
				cur = cur->next;
			} 
			pre->next = cur->next;
			cur->next->prev = pre;
		} else {
			cur = tail;
			for (int i = 0; i < size-pos-1; i++) {
				pre = cur;
				cur = cur->prev;
			}
			pre->prev = cur->prev;
			cur->prev->next = pre;
		}
		delete cur;
	}
};

int main () {
	vector <int> vect ({1,2,3,4,5,6,7,8,9,10});
	LinkedList list(vect);
	list.displayTail();
	list.pop_pos(3);
	list.displayHead();
	return 0;
}