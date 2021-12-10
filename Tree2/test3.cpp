#include <iostream>
#include "TreeNode.h"

using namespace std;

// search with insertion
template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
	if (tree == NULL) // key not in tree, insert
		tree = new TreeNode<T>(key);
	else if (key < tree->item)
		tree->leftTree = search(key, tree->leftTree);
	else if (key > tree->item)
		tree->rightTree = search(key, tree->rightTree);

	return tree;
}

TreeNode<int>* bst()
{
	// given 6, 23, 12, 69, 17, 29, 7
	// after sorting: 6, 7, 12, 17, 23, 29, 69

	// using search with insertion method to build the balanced BST
	TreeNode<int>* tree = NULL;

	// build root
	tree = search(17, tree);

	//build left tree middle, then left, then right
	tree = search(7, tree);
	tree = search(6, tree);
	tree = search(12, tree);

	//build right tree middle, then left, then right
	tree = search(29, tree);
	tree = search(23, tree);
	tree = search(69, tree);

	return tree;
}

int sigma(TreeNode<int>* tree)
{
	if (tree == NULL)
		return 0;
	else
		return tree->item + sigma(tree->leftTree) + sigma(tree->rightTree);
}

int maxnum(TreeNode<int>* tree)
{
	// return the smallest integer number defined in the system
	// so it is unlikely to be taken as the maximum number in the tree
	if (tree == NULL)
		return -INT_MAX;

	int max_n = tree->item;
	int temp_n = maxnum(tree->leftTree);
	if (temp_n > max_n)
		max_n = temp_n;
	temp_n = maxnum(tree->rightTree);
	if (temp_n > max_n)
		max_n = temp_n;

	return max_n;
}

int main()
{
	// build the bst
	TreeNode<int>* tree = bst();

	// sigma
	cout << "sum of the nodes = " << sigma(tree) << "\n";

	// maxnum
	cout << "Maximum number in the tree = " << maxnum(tree) << "\n";

	// depth
	cout << "Depth of the tree = " << tree->depth() << "\n";

	// search using the search function in the TreeNode class

	cout << tree->search(69) << "\n";

	cout << tree->search(70) << "\n";

	// search using the insertion function

	tree = search(69, tree);
	tree = search(70, tree);

	cout << "Depth of tree = " << tree->depth() << "\n";
	cout << "Maximum number in the tree = " << maxnum(tree) << "\n";
	cout << "sum of the nodes = " << sigma(tree) << "\n";


	// free the tree memory
	delete tree;

	return 0;
}