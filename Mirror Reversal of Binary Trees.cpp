#include <iostream>
using namespace std;

struct BinaryTreeNode {
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

/* Display Mirror Reversal of Binary Trees. */
void MirrorReversalOfBinaryTrees(BinaryTreeNode *root) {
	/* Deceide whether the root node, root->left node and the root->right node are NULL. */
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;
	
	/* Exchange the left node of the root; */
	BinaryTreeNode *tmp;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	/* Recursive call MirrorReversalOfBinaryTrees on the root->left node. */
	if (root->left != NULL)
		MirrorReversalOfBinaryTrees(root->left);
	
	/* Recursive call MirrorReversalOfBinaryTrees on the root->right node.*/
	if (root->right != NULL)
		MirrorReversalOfBinaryTrees(root->right);

	return;
}

/* Display Mirror Reversal of Binary Trees. */
BinaryTreeNode * MirrorReversalOfBinaryTrees(BinaryTreeNode *root) {
	
	/* Decide whether the root node equals to NULL. */
	if (root == NULL)
		return root;

	/* Decide whether the root->left or root->right equals to NULL. */
	if (root->left == NULL && root->right == NULL)
		return NULL;

	/* Exchange the left node of the root; */
	BinaryTreeNode *tmp;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	/* Recursive call MirrorReversalOfBinaryTrees on the root->left node.*/
	if (root->left != NULL)
		MirrorReversalOfBinaryTrees(root->left);

	/* Recursive call MirrorReversalOfBinaryTrees on the root->right node.*/
	if (root->right != NULL)
		MirrorReversalOfBinaryTrees(root->right);

	return root;
}

int main(int argc, const char * argv[]) {
	return 0;
}

