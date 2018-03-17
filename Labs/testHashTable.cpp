#include <iostream>
#define NOT_FOUND -101
using namespace std;

class llist {
private:
	struct node {
		int data;
		node *next;
	};

	node *head, *tail;
	int size;

public:
	llist () {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int get_size () {
		return size;
	}

	int search (int val) {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			if (temp->data == val) return temp->data;
			temp = temp->next;
		}
		return NOT_FOUND;
	}

	void create (int val) {
		node *temp = new node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		} else {
			tail->next = temp;
			tail = temp;
		}
	}

	void remove (int val) {
		node *pre = new node;
		node *cur = new node;
		cur = head;
		while (cur->data != val && cur != NULL) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		delete cur;
		size--;
	}
};

int main () {
	llist hash_table[101];
	hash<string> myHash;
	string key;
	int value;

	while (cin >> key >> value, value != -1) {
		hash_table[myHash(key)%101].create(value);
	}
	return 0;
}
