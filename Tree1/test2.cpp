#include "TreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	// build week day tree
	// leaf nodes first
	TreeNode<string>* fri = new TreeNode<string>("Friday");
	TreeNode<string>* sat = new TreeNode<string>("Saturday");
	TreeNode<string>* thu = new TreeNode<string>("Thursday");
	TreeNode<string>* wed = new TreeNode<string>("Wednesday");
	// nodes on lvl 1
	TreeNode<string>* mon = new TreeNode<string>("Monday", fri, sat);
	TreeNode<string>* tue = new TreeNode<string>("Tuesday", thu, wed);
	// root node
	TreeNode<string>* tree = new TreeNode<string>("Sunday", mon, tue);

	//search

	string day;
	do {
		cout << "Which day are you searching for?: ";
		cin >> day;
		if (tree != NULL && tree->search(day))
			cout << "Found." << "\n";
		else
			cout << "Not found - are you sure you input a day? Try again and watch your spelling!" << "\n";
	} while (!tree->search(day));

	// depth
	if (tree != NULL)
		cout << "Depth of the tree = " << tree->depth() << "\n";
	else
		cout << "Depth of the tree = 0" << "\n";

	// free tree memory
	delete tree;

	return 0;
}