//
//  main.cpp
//  Binary Tree Inorder Traversal
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//定义二叉树节点；
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
        vector<int> inorderTraversal(TreeNode* root) {
                vector<int> v;
                stack<TreeNode *> s;
                TreeNode * tree = root;
                while (tree != NULL || s.empty() != true) {
                        if (tree != NULL) {
                                s.push(tree);
                                tree = tree->left;
                        }
                        else {
                                tree = s.top();
                                v.push_back(tree->val);
                                s.pop();
                                tree = tree->right;
                        }
                }
                return v;
        }

        void inorderTraversal_1(TreeNode* root) {
                if (root != NULL) {
                        inorderTraversal_1(root->left);
                        cout << root->val << endl;
                        inorderTraversal_1(root->right);
                }
        }
};
int main() {
}
