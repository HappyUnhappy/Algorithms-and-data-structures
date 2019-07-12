#pragma once

template <typename T>
struct TreeNode {
	T m_key;

	TreeNode *parent;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

template <typename T>
class BinarySearchTree {
	TreeNode<T> *m_root;

	TreeNode *insert(TreeNode *node, T value);

public:
	BinarySearchTree();
	~BinarySearchTree();

	void insert(const T value);
	void iterativeInsert(const T value);
	void remove(const T value);
	void search(const T value);
	
	void printTreeInOrder();
	void printTreePreOrder;
	void printTreePostOrder();
};
