#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL);
	~TreeNode();

	T item;
	TreeNode<T>* leftTree, * rightTree;

	bool search(T key);
	int depth();

private:
};

template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* left, TreeNode<T>* right)
	: item(i), leftTree(left), rightTree(right)
{
}

template <typename T>
TreeNode<T>::~TreeNode()
{
	delete leftTree;
	delete rightTree;
}

template <typename T>
bool TreeNode<T>::search(T key)
{
	// is the current item the key?
	// Back out of search and return true. This is the base case
	if (item == key)
		return true;

	//Branch left search - are we in the left tree?
	// If so, search the left tree
	bool bl = false;
	if (leftTree)
		bl = leftTree->search(key);

	//Branch right search - are we in the right tree?
	// If so, search the right tree
	bool br = false;
	if (rightTree)
		br = rightTree->search(key);

	return bl || br;
}

template <typename T>
int TreeNode<T>::depth()
{
	// recursively check depth left
	int dl = 0;
	if (leftTree)
		dl = leftTree->depth();

	// recursively check depth right
	int dr = 0;
	if (rightTree)
		dr = rightTree->depth();

	if (dl < dr)
		return dr + 1;
	else
		return dl + 1;
}

#endif 

