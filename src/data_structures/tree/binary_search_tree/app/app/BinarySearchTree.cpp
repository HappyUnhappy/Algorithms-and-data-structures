#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}

template <typename T>
TreeNode<T> * BinarySearchTree<T>::insert(TreeNode<T> *node, T value) {

	// if root doesn't exist or there isn't any child node
	if (node == nullptr) {
		node = new TreeNode;
		node->m_key = value;
		node->parent = nullptr;
		node->leftChild = nullptr;
		node->rightChild = nullptr;
	}
	else {
		//if the given key is greater than node's key then go to the right subtree
		if (node->m_key < value) {
			node->rightChild = insert(node->rightChild, value);
			node->rightChild->parent = node;
		}
		//if the given key is samller than node's key then go to the left subtree
		else {
			node->leftChild = insert(node->leftChild, value);
			node->leftChild->parent = node;
		}
	}

	return node;
}

template <typename T>
void BinarySearchTree<T>::insert(const T value) {
	m_root = insert(m_root, value);
}