//
//  main.cpp
//  Binary Tree Preorder Traversal
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//定义二叉树的数据结构；
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
        vector<int> preorderTraversal(TreeNode* root) {
                vector<int> v;
                if(root == NULL) {
                        return v;
                }
        
                TreeNode * t=root;
                stack<TreeNode *> s;
                s.push(t);
        
                while(s.empty() != true) {
                        t = s.top();
                        v.push_back(t->val);
                        s.pop();
            
                        if(t->right != NULL) {
                                s.push(t->right);
                        }
                        if(t->left != NULL) {
                                s.push(t->left);
                        }
                }
                return v;
        }
        void preorderTraversal_1(TreeNode* root) {
                if (root != NULL) {
                        Display(root);
                }
                if (root->left != NULL) {
                        preorderTraversal_1(root->left);
                }
                if (root->right != NULL) {
                        preorderTraversal_1(root->right); 
                }
        }
};
int main() {
}
