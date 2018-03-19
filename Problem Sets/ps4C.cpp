#include <iostream>
using namespace std;

class binarySearchTree {
	protected:
		struct node {
			node* parent;
			node* left;
			node* right;
			string key;
			int height;
		};
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

		node* getmin(node* temp) {
			if (temp == NULL) return NULL;
			else if (temp->left == NULL) return temp;
			else return getmin(temp->left);
		}

		node* getmax(node* temp) {
			if (temp == NULL) return NULL;
			else if (temp->right == NULL) return temp;
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
				return (par == NULL) ? NULL : par;
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
				return (par == NULL) ? NULL : par;
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
				int factor1 = h(temp->left->left) - h(temp->left->right);
				if (factor1 == 1) temp = rotateRight(temp);
				else {
					temp->left = rotateLeft(temp->left);
					temp = rotateRight(temp);
				}
			} else if (factor == -2) {
				int factor1 = h(temp->right->left) - h(temp->right->right);
				if (factor1 == -1) temp = rotateLeft(temp);
				else {
					temp->right = rotateRight(temp->right);
					temp = rotateLeft(temp);
				}
			}
			temp->height = max(h(temp->left), h(temp->right)) + 1;
			return temp;
		}

		void range(string lower, string upper, node*temp) {
			if (temp == NULL || temp->key >= upper) return;
			count++;
			range(lower, upper, successor(temp));
		}

		node* lower_bound (node* temp, string value) {
	        node * prev = NULL;
	        while (temp != NULL) {
	            if (value < temp->key) {
	                prev = temp;
	                temp = temp->left;
	            } else if (temp->key == value) return temp;
	            else temp = temp->right;
	        }
        	return prev;
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

		int getSize() {return size;}

		int range(string lower, string upper) {
			count = 0;
			node* temp = lower_bound(root, lower);
			range(lower,upper, temp);
			return count;
		}
};

int main () {
	int operation, count, gender;
	string name, lower, upper;
	binarySearchTree boy[26], girl[26];

	while (cin >> operation, operation) {
		if (operation == 1) {
			cin >> name >> gender;
			if (gender == 1) boy[name[0]-'A'].insert(name);
			else girl[name[0]-'A'].insert(name);
		} else {
			count = 0;
			cin >> lower >> upper >> gender;
			if (!gender || gender == 1) {
				count += boy[lower[0]-'A'].range(lower,upper);
				if (lower[0] != upper[0]) {
					for (char i = lower[0]+1; i < upper[0]; i++) count += boy[i-'A'].getSize();
					count += boy[upper[0]-'A'].range(lower,upper);
				}
			} 
			if (!gender || gender == 2) {
				count += girl[lower[0]-'A'].range(lower,upper);
				if (lower[0] != upper[0]) {
					for (char i = lower[0]+1; i < upper[0]; i++) count += girl[i-'A'].getSize();
					count += girl[upper[0]-'A'].range(lower,upper);
				}
			}
			cout << count << endl;
		}
	}
	return 0;
}