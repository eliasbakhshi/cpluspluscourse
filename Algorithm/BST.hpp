#ifndef BST_HPP
#define BST_HPP

#include <string>

template <class T>
class BST {
private:
	class Node {
	public:
		T data;
		Node* left;
		Node* right;
		Node* parent;

		Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
	};

	Node* root;
	Node* insertRec(Node* currentRoot, T element);
public:
	BST();

	virtual ~BST();

	void insert(T element);

	T getMin();

	T find(T element);

	void remove(T element);


	std::string inorderTraversalRec(Node* current);
	std::string postorderTraversalRec(Node* current);
	std::string preorderTraversalRec(Node* current);

	std::string inOrderTraversal();
	std::string preOrderTraversal();
	std::string postOrderTraversal();

	std::string toGraphviz();
	std::string toGraphvizRec(std::string data, Node* current, int& nodeID);
	void free(Node* current);
};

template<class T>
inline typename BST<T>::Node* BST<T>::insertRec(Node* currentRoot, T element) {
	if (currentRoot == nullptr) {
		return new Node(element);
	}
	if (element < currentRoot->data) 
		currentRoot->left = insertRec(currentRoot->left, element);
	else 
		currentRoot->right = insertRec(currentRoot->right, element);

	return currentRoot;
}

template <class T>
BST<T>::BST() : root(nullptr) {

}

template <class T>
BST<T>::~BST() {
	free(root);
	root = nullptr;
}
template <class T>
void BST<T>::insert(T element) {

	root = insertRec(root, element);

	// iteration
	/*if (root == 0) {
		root = new Node(element);
	} else {
		Node* newNode = new Node(element);
		Node* current = root;
		Node* parent = nullptr;
		while (current != nullptr) {
			parent = current;
			element > current->data ? current = current->right : current = current->left;
		}
		element > parent->data ? parent->right = newNode : parent->left = newNode;
		newNode->parent = parent;
	}*/
}
template <class T>
T BST<T>::getMin() {
	if (root == nullptr) {
		throw std::exception("Tree is empty");
	}

	Node* current = root;
	while (current->left != nullptr) {
		current = current->left;
	}

	return current->data;
}


template <class T>
T BST<T>::find(T element) {
	Node* current = root;

	while (current != nullptr) {
		if (current->data == element) {
			return current->data;
		} else if (element < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	throw std::exception("Element not found");
}


template <class T>
void BST<T>::remove(T element) {
	if (root == nullptr) {
		throw std::exception("Tree is empty");
	}

	Node* current = root;
	Node* parent = nullptr;
	bool isLeftChild = false;

	// Search for the node to be deleted and its parent
	while (current != nullptr && current->data != element) {
		parent = current;
		if (element < current->data) {
			current = current->left;
			isLeftChild = true;
		} else {
			current = current->right;
			isLeftChild = false;
		}
	}

	if (current == nullptr) {
		throw std::exception("Element not found");
	}

	// Case 1: Node to be deleted has no children
	if (current->left == nullptr && current->right == nullptr) {
		if (current == root) {
			root = nullptr;
		} else if (isLeftChild) {
			parent->left = nullptr;
		} else {
			parent->right = nullptr;
		}
		delete current;
	}
	// Case 2: Node to be deleted has one child
	else if (current->left == nullptr) {
		if (current == root) {
			root = current->right;
		} else if (isLeftChild) {
			parent->left = current->right;
		} else {
			parent->right = current->right;
		}
		delete current;
	} else if (current->right == nullptr) {
		if (current == root) {
			root = current->left;
		} else if (isLeftChild) {
			parent->left = current->left;
		} else {
			parent->right = current->left;
		}
		delete current;
	}
	// Case 3: Node to be deleted has two children
	else {
		// Find the successor (minimum node in the right subtree)
		Node* successor = current->right;
		Node* successorParent = current;
		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		// Copy the data from the successor to the current node
		current->data = successor->data;

		// Delete the successor node (it has at most one child)
		if (successor == successorParent->left) {
			successorParent->left = successor->right;
		} else {
			successorParent->right = successor->right;
		}
		delete successor;
	}
}

template<class T>
inline void BST<T>::free(Node* current) {
	if (current != nullptr) {
		free(current->left);
		free(current->right);
		delete current;
	}
}

template<class T>
inline std::string BST<T>::inorderTraversalRec(Node* current) {
	std::string res;
	if (current != nullptr) {
		res += inorderTraversalRec(current->left);
		res += std::to_string(current->data) + ",";
		res += inorderTraversalRec(current->right);
	}
	return res;
}

template<class T>
inline std::string BST<T>::preorderTraversalRec(Node* current) {
	std::string res;
	if (current != nullptr) {
		res += std::to_string(current->data) + ",";
		res += preorderTraversalRec(current->left);
		res += preorderTraversalRec(current->right);
	}
	return res;
}

template<class T>
inline std::string BST<T>::postorderTraversalRec(Node* current) {
	std::string res;
	if (current != nullptr) {
		res += postorderTraversalRec(current->left);
		res += postorderTraversalRec(current->right);
		res += std::to_string(current->data) + ",";
	}
	return res;
}

template <class T>
std::string BST<T>::inOrderTraversal() {
	return inorderTraversalRec(root);
}

template <class T>
std::string BST<T>::preOrderTraversal() {
	return preorderTraversalRec(root);
}

template <class T>
std::string BST<T>::postOrderTraversal() {
	return postorderTraversalRec(root);
}

template <class T>
std::string BST<T>::toGraphviz() {
	int nodeID = 0;
	std::string data = "";
	if (root != nullptr) {
		data += "digraph {\n";
		data += "\tRoot [shape=plaintext];\n";
		data += "\t\"Root\" -> 0 [color=black];\n";
		data = toGraphvizRec(data, this->root, nodeID);
		data += "}\n";
	}
	return data;
}

template <class T>
std::string BST<T>::toGraphvizRec(std::string data, Node* current, int& nodeID) {
	int my_nodeID = nodeID;
	data += "\t" + std::to_string(my_nodeID) + " [label=\"" + std::to_string(current->data) + "\"];\n";
	nodeID++;
	if (current->left != nullptr) {
		data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [color=blue];\n";
		data = toGraphvizRec(data, current->left, nodeID);
	} else {
		data += "\t" + std::to_string(nodeID) + " [label=nill,style=invis];\n";
		data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [style=invis];\n";
	}
	nodeID++;
	if (current->right != nullptr) {
		data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [color=red];\n";
		data = toGraphvizRec(data, current->right, nodeID);
	} else {
		data += "\t" + std::to_string(nodeID) + " [label=nill,style=invis];\n";
		data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [style=invis];\n";
	}
	return data;
}

#endif