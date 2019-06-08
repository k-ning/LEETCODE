//
//  main.cpp
//  Binary Tree Level Order Traversal
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
        vector<vector<int>> levelOrder(TreeNode* root) {

                vector<vector<int>> v;
                if (root == NULL)
                        return v;
        
                TreeNode* tree = root;
                queue<TreeNode*> q;
                q.push(tree);
        
                vector<int> temp;
                int size = (int)q.size();
        
                while (q.empty() != true) {
                        while (size != 0) {
                                tree = q.front();
                                q.pop();
                                temp.push_back(tree->val);
                
                                if (tree->left != NULL) {
                                        q.push(tree->left);
                                }
                                if (tree->right != NULL) {
                                        q.push(tree->right);
                                }
                                size--;
                        }
                        size = (int)q.size();
                        v.push_back(temp);
                        temp.clear();
                }
                return v;
        }
        
        vector<vector<int>> levelOrder_new(TreeNode* root) {

                vector<vector<int>> binaryTree;
                vector<int> binaryTreeTemp;
                queue<TreeNode*> treeNodeQueue;
                TreeNode* node = root;
                int size = 0;
        
                if (root == NULL)
                        return binaryTree;
        
                treeNodeQueue.push(node);
                binaryTreeTemp.push_back(node->val);
        
                while (treeNodeQueue.empty() != true) {
                        binaryTree.push_back(binaryTreeTemp);
                        binaryTreeTemp.clear();
                        size = treeNodeQueue.size();
            
                        while (size != 0) {
                                node = treeNodeQueue.front();
                                treeNodeQueue.pop();
                
                                if (node->left != NULL) {
                                        treeNodeQueue.push(node->left);
                                        binaryTreeTemp.push_back(node->left->val);
                                }
                
                                if (node->right != NULL) {
                                        treeNodeQueue.push(node->right);
                                        binaryTreeTemp.push_back(node->right->val);
                                }
                                size--;
                        }
                }
                return binaryTree;
        }
};
int main() {

}
