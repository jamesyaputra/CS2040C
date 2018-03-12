#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class myStack {
	private:
		node *head, *tail;
		int size;
	public:
		myStack() {
			head = NULL;
			tail = NULL;
			size = 0;
		}

		int get_size() {
			return size;
		}

		int pop() {
			node *temp = new node;
			temp = head;
			head = temp->next;
			size--;
			return temp->data;
		}

		int top() {
			if (head != NULL) return head->data;
			else return -1;
		}

		void create(int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			if (head == NULL) {
				head = temp;
				tail = temp;
				temp = NULL;
			} else {
				temp->next = head;
				head = temp;
			}
			size++;
		}
	
		void push(int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
			size++;
		}

		void remove() {
			node *temp = new node;
			temp = head;
			head = temp->next;
			size--;
			delete temp;
		}
};

int main(int argc, char const *argv[]) {

	return 0;
}