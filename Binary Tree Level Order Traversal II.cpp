//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL)
            return v;
        
        TreeNode * tree = root;
        queue<TreeNode *> q;
        q.push(tree);
        
        vector<int> temp;
        stack<vector<int>> s;
        int size = (int)q.size();
        
        while (q.empty() != true) {
            while (size != 0) {
                tree = q.front();
                temp.push_back(tree->val);
                q.pop();
                
                if (tree->left != NULL) {
                    q.push(tree->left);
                }
                if (tree->right != NULL) {
                    q.push(tree->right);
                }
                size--;
            }
            size = (int)q.size();
            s.push(temp);
            temp.clear();
        }
        while (s.empty() != true) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
