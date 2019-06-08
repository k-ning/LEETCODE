//
//  main.cpp
//  Binary Tree Postorder Traversal
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
        vector<int> postorderTraversal(TreeNode* root) {
                TreeNode * tree = root;
                vector<int> v;
                if (root == NULL)
                        return v;
                stack<TreeNode *> s1,s2;
                s1.push(tree);

                while (s1.empty() != true) {
                        tree = s1.top();
                        s2.push(tree);
                        s1.pop();
                        if (tree->left != NULL)
                                s1.push(tree->left);
                        if (tree->right != NULL)
                                s1.push(tree->right);
                }

                while (s2.empty() != true) {
                        tree = s2.top();
                        v.push_back(tree->val);
                        s2.pop();
                }
                return v;
        }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
