#include <iostream>
#include <vector>
using namespace std;


class LinkedList{
	private:
		struct node {
			int data;
			node *next;
		};
		node *head, *tail;
		int size;
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}

		LinkedList(vector<int> vect) {
			size = 0;
			while (!vect.empty()) {
				create(vect.back());
				vect.pop_back();
			}
		}

		int getSize() {
			return size;
		}

		int get(int pos) {
			if (pos < 0 || pos > size-1) return -1;
			node *temp = new node;
			temp = head;
			for (int i = 0; i < pos; i++) {
				temp = temp->next;
			}
			return temp->data;
		}

		void display() {
			node *temp = new node;
			temp = head;
			while(temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
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
				tail->next = temp;
				tail = temp;
			}
			size++;
		}
		
		void push_front(int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
			size++;
		}

		void push_back(int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
			size++;
		}

		void push_pos(int pos, int value) {
			node *pre = new node;
			node *cur = new node;
			node *aft = new node;
			cur = head;
			for (int i = 0; i < pos; i++) {
				pre = cur;
				cur = cur->next;
			}
			aft->data = value;
			pre->next = aft;
			aft->next = cur;
			size++;
		}

		void pop_front() {
			if (head == NULL) return;
			node *temp = new node;
			temp = head;
			head = temp->next;
			delete temp;
			size--;
		}

		void pop_back() {
			if (tail == NULL) return;
			node *pre = new node;
			node *cur = new node;
			cur = head;
			while(cur->next != NULL) {
				pre = cur;
				cur = cur->next;
			}
			tail = pre;
			tail->next = NULL;
			delete cur;
			size--;
		}

		void pop_pos(int pos) {
			node *pre = new node;
			node *cur = new node;
			cur = head;
			for (int i = 0; i < pos; i++) {
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			size--;
		}

		void reverse() {
			node *temp = new node;
			node *pre = new node;
			node *cur = new node;

			temp = NULL;
			pre = head;
			for (int i = 0; i < size; i++) {
				cur = pre->next;
				pre->next = temp;
				temp = pre;
				pre = cur;
			}
			temp = head;
			head = tail;
			tail = temp;
		}
};

int main(int argc, char const *argv[]) {
	vector<int> myVector ({1,2,3,4,5,6,7,8,9,10});
	LinkedList list(myVector);
	list.display();
	list.reverse();
	list.display();

	return 0;
}