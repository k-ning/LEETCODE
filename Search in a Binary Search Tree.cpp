#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), rigth(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return root;
        
        if (root->val == val)
        	return root;
        if (root->val > val) 
        	return searchBST(root->left, val);
        else
        	return searchBST(root->right, val);
}