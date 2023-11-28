#pragma once

#include <iostream>
using namespace std;

struct Node
{
	int key;
	int index;
	Node* left;
	Node* right;

	Node& operator=(const Node& b)
	{
		this->key = b.key;
		this->index = b.index;
		this->left = b.left;
		this->right = b.right;
		return *this;
	}
};

class BST
{
private:
	Node* Root;

	void insertUnderwrap(Node*& T, int key, int index) {// edits the original tree
		if (T == nullptr  || T->key == key)// if the passed node is non-existent or has the same key
			T = createNode(key, index);// create a node or overwrite
		else if (key < T->key) {// else look for a match
			insertUnderwrap(T->left, key, index);
		}
		else if (key > T->key) {
			insertUnderwrap(T->right, key, index);
		}
	}

	Node* createNode(int key, int index) {// a util to create nodes. Basically create and handle
		Node* root = new Node;
		root->key = key;
		root->index = index;
		root->left = root->right = nullptr;
		return root;
	}

	Node* searchNode(Node* root, int key) {// returns copy of node with a requested key
		if (root == nullptr) {
			return nullptr;
		}
		else if (root->key == key) {
			return root;
		}
		else if (root->key > key) {
			searchNode(root->left, key);
		}
		else {
			searchNode(root->right, key);
		}
	}

	Node* minValueNode(Node* node) {
		Node* current = node;
		while (current && current->left != nullptr)
			current = current->left;

		return current;
	}

	Node* deleteNode(Node* root, int key) {
		if (root == nullptr) return root;

		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else {
			if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}

			Node* temp = minValueNode(root->right);

			root->key = temp->key;

			root->right = deleteNode(root->right, temp->key);
		}
		return root;
	}

	void displayTree(Node* root) {
		if (root == nullptr) return;

		displayTree(root->left);
		cout << "{" << root->key << ", " << root->index << "}" << '\n';
		displayTree(root->right);
	}

public:
	BST() {
		Root = nullptr;
	}

	void insert(int key, int index) {
		insertUnderwrap(this->Root, key, index);
	}

	Node* search(int key) { //a wrapper to search method
		return searchNode(this->Root, key);
	}

	int erase(int key) {
		Node* temp = search(key);
		if (temp == nullptr)
		{
			return -1;
		}
		else
		{
			int index = temp->index;
			this->Root = deleteNode(this->Root, key);
			return index;
		}
	}

	void display() {
		displayTree(this->Root);
	}

	BST& operator=(const BST& b)
	{
		this->Root = b.Root;
		return *this;
	}
};

