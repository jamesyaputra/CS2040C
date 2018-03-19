#include <iostream>
using namespace std;

struct node {
	node* parent;
	node* left;
	node* right;
	string key;
	int height;
};

class binarySearchTree {
	protected:
		node *root;
		int size, count;

		int h(node* temp) {
			return temp == NULL ? -1 : temp->height;
		}

		node* rotateLeft(node* temp) {
			node* x = temp->right;
			x->parent = temp->parent;
			temp->parent = x;
			temp->right = x->left;
			if (x->left != NULL) x->left->parent = temp;
			x->left = temp;
			temp->height = max(h(temp->left), h(temp->right)) + 1;
			x->height = max(h(x->left), h(x->right)) + 1;
			return x;
		}

		node* rotateRight(node* temp) {
			node* x = temp->left;
			x->parent = temp->parent;
			temp->parent = x;
			temp->left = x->right;
			if (x->right != NULL) x->right->parent = temp;
			x->right = temp;
			temp->height = max(h(temp->left), h(temp->right)) + 1;
			x->height = max(h(x->left), h(x->right)) + 1;
			return x;
		}

		node* search(node* temp, string value) {
			if (temp->key == value) return temp;
			else if (temp-> key < value) return search(temp->right, value);
			else return search(temp->left, value);
		}

		node* getmin(node* temp) {
			if (temp->left == NULL) return temp;
			else return getmin(temp->left);
		}

		node* getmax(node* temp) {
			if (temp->right == NULL) return temp;
			else return getmax(temp->right);
		}

		node* successor(node* temp) {
			if (temp->right != NULL) {
				return getmin(temp->right);
			} else {
				node* par = temp->parent;
				node* cur = temp;

				while (par != NULL && cur == par->right){
					cur = par;
					par = cur->parent;
				}
				return par;
			}
		}

		node* predecessor(node* temp) {
			if (temp->left != NULL) {
				return getmax(temp->left);
			} else {
				node* par = temp->parent;
				node* cur = temp;

				while (par != NULL && cur == par->left){
					cur = par;
					par = cur->parent;
				}
				return par;
			}
		}

		node* insert (node* temp, string value) {
			if (temp == NULL) {
				temp = new node;
				temp->key = value;
				temp->parent = temp->left = temp->right = NULL;
				temp->height = 0;
			} else if (temp->key < value) {
				temp->right = insert(temp->right, value);
				temp->right->parent = temp;
			} else {
				temp->left = insert(temp->left, value);
				temp->left->parent = temp;
			}

			int factor = h(temp->left) - h(temp->right);
			if (factor == 2) {
				int balance2 = h(temp->left->left) - h(temp->left->right);
				if (balance2 == 1) temp = rotateRight(temp);
				else {
					temp->left = rotateLeft(temp->left);
					temp = rotateRight(temp);
				}
			} else if (factor == -2) {
				int balance2 = h(temp->right->left) - h(temp->right->right);
				if (balance2 == -1) temp = rotateLeft(temp);
				else {
					temp->right = rotateRight(temp->right);
					temp = rotateLeft(temp);
				}
			}
			temp->height = max(h(temp->left), h(temp->right)) + 1;
			return temp;
		}

		node* remove(node* temp, string value) {
			if (temp == NULL) return temp;
			if (temp->key == value) {
				if (temp->left == NULL && temp->right == NULL) {
					temp = NULL;
				} else if (temp->left == NULL && temp->right != NULL) {
					temp->right->parent = temp->parent;
					temp = temp->right;
				} else if (temp->left != NULL && temp->right == NULL) {
					temp->left->parent = temp->parent;
					temp = temp->left;
				} else {
					string succ = successor(temp)->key;
					temp->key = succ;
					temp->right = remove(temp->right, succ);
				}
			} else if (temp->key < value) {
				temp->right = remove(temp->right, value);
			} else {
				temp->left = remove(temp->left, value);
			}

			if (temp != NULL) {
				int factor = h(temp->left) - h(temp->right);
				if (factor == 2) {
					int balance2 = h(temp->left->left) - h(temp->left->right);
					if (balance2 == 1) temp = rotateRight(temp);
					else {
						temp->left = rotateLeft(temp->left);
						temp = rotateRight(temp);
					}
				} else if (factor == -2) {
					int balance2 = h(temp->right->left) - h(temp->right->right);
					if (balance2 == -1) temp = rotateLeft(temp);
					else {
						temp->right = rotateRight(temp->right);
						temp = rotateLeft(temp);
					}
				}
				temp->height = max(h(temp->left), h(temp->right)) + 1;
			}
			return temp;
		}

		node* lower_bound (node* temp, string value) {
	        node* prev = NULL;
	        while (temp != NULL) {
	            if (value < temp->key) {
	                prev = temp;
	                temp = temp->left;
	            } else if (temp->key == value) return temp;
	            else temp = temp->right;
	        }
        	return prev;
   		}

   		node* upper_bound (node* temp, string value) {
   			node* prev = NULL;
   			while (temp != NULL) {
   				if (value > temp->key) {
   					prev = temp;
   					temp = temp->right;
   				} else temp = temp->left;
   			}
   			return prev;
   		}

   		void distance (node* lower, node* upper) {
   			if (lower == NULL || upper == NULL || lower->key > upper->key) return;
   			count++;
   			distance(successor(lower), upper);
   		}

		int getHeight(node* temp) {
			if (temp == NULL) return -1;
			else return max(getHeight(temp->left), getHeight(temp->right)) + 1;
		}
	public:
		binarySearchTree() {
			root = NULL;
			size = 0;
		}

		void insert(string value) {
			root = insert(root, value);
			size++;
		}

		void remove(string value) {
			root = remove(root, value);
			size--;
		}

		string search(string value) {
			node* temp = search(root, value);
			return (temp == NULL)? "$" : temp->key;
		}

		string lower_bound (string value) {
			return lower_bound(root, value)->key;
		}

		string upper_bound(string value) {
			return upper_bound(root, value)->key;
		}
		int getSize() {return size;}

		int distance(string lower, string upper) {
			count = 0;
			node* low = lower_bound(root, lower);
			node* up = upper_bound(root, upper);
			distance(low, up);
			return count;
		}

		int getHeight() {
			return getHeight(root);
		}
};

int main () {
	binarySearchTree test;
	test.insert("James");

	cout << test.lower_bound("A") << endl;
	cout << test.upper_bound("Yeye") << endl;
	cout << test.distance("A", "Yeye") << endl;
	cout << test.getHeight() << endl;
	return 0;
}