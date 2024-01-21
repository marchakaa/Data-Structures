#include <iostream>
#include <algorithm>
#include <string>

template <class T>
struct BinTreeNode
{
	T data;
	BinTreeNode* left, * right;

	BinTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

};
template <class T>
class BinTree
{
public:
	BinTree() : root(nullptr) {}

	~BinTree() {
		clear(root);
	}

    void clear(BinTreeNode<T> *node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

	void insert(T value) {
		if (root) {
			insertNode(root, value);
		} else {
			root = new BinTreeNode<T>(value);
		}
	}

	void insertNode(BinTreeNode<T>* node, T value) {
		if (value < node->data) {
			if (node->left) {
				insertNode(node->left, value);
			} else {
				node->left = new  BinTreeNode<T>(value);
			}
		} else {
			if (node->right) {
				insertNode(node->right, value);
			} else {
				node->right = new BinTreeNode<T>(value);
			}
		}
	}

	int count() const {
		return countNodes(root);
	}

	int countEvens() const {
		return countEvenNodes(root);
	}

	void print() const {
		inOrderPrint(root);
		std::cout << std::endl;
	}

	int searchCount(bool (*pred)(const T&)) {
		return searchCountHelper(root, pred);
	}

	int height() {
		return heightHelper(root);
	}

	int countLeaves() {
		return countLeavesHelper(root);
	}

	T maxLeaf() const {
		return maxLeafHelper(root);
	}
	T& getElement(const char* s) {
		return getElementHelper(root, s);
	}

	void printScheme() const {
		printSchemeHelper(root);
	}

	void printHaskell() const {
		printHaskellHelper(root, 0);
	}
private:
	BinTreeNode<T>* root;

	void inOrderPrint(BinTreeNode<T>* node) const {
		if (node != nullptr) {
			inOrderPrint(node->left);
			std::cout << node->data << " ";
			inOrderPrint(node->right);
		}
	}

	int countNodes(BinTreeNode<T>* node) const {
		if (node != nullptr) {
			return 1 + countNodes(node->left) + countNodes(node->right);
		}
		return 0;
	}

	int countEvenNodes(BinTreeNode<T>* node) const {
		if (node) {
			if (node->data % 2 == 0) {
				return 1 + countEvenNodes(node->left) + countEvenNodes(node->right);
			} else {
				return countEvenNodes(node->left) + countEvenNodes(node->right);
			}
		}
		return 0;
	}

	int searchCountHelper(BinTreeNode<T>* node, bool (*pred)(const T&)) {
		if (node) {
			if (pred(node->data)) {
				return 1 + searchCountHelper(node->left, pred) + searchCountHelper(node->right, pred);
			} else {
				return searchCountHelper(node->left, pred) + searchCountHelper(node->right, pred);
			}
		}
		return 0;
	}

	int heightHelper(BinTreeNode<T>* node) {
		if (node) {
			return 1 + std::max(heightHelper(node->left), heightHelper(node->right));
		}
		return 0;
	}

	int countLeavesHelper(BinTreeNode<T>* node) {
		if (node) {
			if (!(node->left) && !(node->right)) {
				return 1;
			}
			return countLeavesHelper(node->left) + countLeavesHelper(node->right);
		}
		return 0;
	}

	T maxLeafHelper(BinTreeNode<T>* node) const {
		if (node) {
			if (node->right) {
				return maxLeafHelper(node->right);
			} else {
				return node->data;
			}
		}
		throw std::runtime_error("Invalid node");
	}

	T& getElementHelper(BinTreeNode<T>* node, const char* s) {
		if (node) {
			if (*s != '\0') {
				if (s[0] == 'L') {
					return  getElementHelper(node->left, &s[1]);
				} else {
					return  getElementHelper(node->right, &s[1]);
				}
			} else {
				return node->data;
			}
		}
		throw std::runtime_error("No such element");
	}

	void printSchemeHelper(BinTreeNode<T>* node) const {
		if (node) {
			std::cout << '(';
			std::cout << node->data;
			std::cout << ' ';
			printSchemeHelper(node->left);
			std::cout << ' ';
			printSchemeHelper(node->right);
			std::cout << ')';
		} else {
			std::cout << "()";
		}
	}

	void digitSize(int data) {
		int res = 0;
		while (data != 0) {
			res++;
			data %= 10;
		}
	}

	void printHaskellHelper(BinTreeNode<T>* node, int margin) const {
		if (node) {
			std::cout "Node " << node->data  <<  ;

		} else {
			std::cout << "Empty";
		}
	}
};

int main() {
	BinTree<int> tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(20);
	tree.insert(15);
	tree.insert(25);
	//tree.insert(1);
	//tree.insert(0);
	//tree.insert(-1);
	//tree.insert(-2);
	//tree.insert(-3);
	//tree.insert(-4);
	//tree.insert(-5);
	//tree.insert(2);
	//tree.insert(3);
	//tree.insert(4);
	//tree.insert(5);
	tree.print();
	std::cout << tree.count() << std::endl;
	std::cout << tree.countEvens() << std::endl;
	std::cout << tree.searchCount([](const int& val) -> bool {
		return val % 2 == 0;
		}) << std::endl;
	std::cout << tree.searchCount([](const auto&) {
		return true;
		}) << std::endl;
	std::cout << tree.height() << std::endl;
	std::cout << tree.countLeaves() << std::endl;
	std::cout << tree.maxLeaf() << std::endl;
	std::cout << tree.getElement("") << std::endl;
	tree.printScheme();
	std::cout << std::endl;
}