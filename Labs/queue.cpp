#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class myQueue {
	private:
		node *head, *tail;
		int size;
	public:
		myQueue() {
			head = NULL;
			tail = NULL;
			size = 0;
		}

		int get_size() {
			return size;
		}

		int dequeue() {
			node *temp = new node;
			temp = head;
			head = temp->next;
			size--;
			return temp->data;
		}

		void enqueue(int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
			size++;
		}

		int top() {
			if (head != NULL) return head->data;
			else return -1;
		}

		int tail() {
			if (tail != NULL) return tail->data;
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
};

int main(int argc, char const *argv[]) {

	return 0;
}