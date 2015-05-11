//
//  main.cpp
//  Construct Binary Tree from Inorder and Postorder Traversal
//
//  Created by 唧唧歪歪 on 15/5/11.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size()==0||postorder.size()==0)
        {
            return NULL;
        }
        if(inorder.size()!=postorder.size())
        {
            return NULL;
        }
        return build(inorder,0,(int)inorder.size()-1,postorder,0,(int)postorder.size()-1);
    }
    //利用递归的方式，建立左子树与右子树；
    TreeNode * build(vector<int> inorder,int a1,int b1,vector<int> postorder,int a2,int b2)
    {
        TreeNode * root=new TreeNode(inorder[a1]);
        
        if(a1==b1&&a2==b2)
        {
            return root;
        }
        //找出当前inorder[a1]元素;
        int i=a2;
        while(i<=b2&&root->val!=postorder[i])
        {
            i++;
        }
        if(i>b2)
        {
            return NULL;
        }
        int length=i-a2;
        if(i==a2)
        {
            root->left=NULL;
        }
        if(i==b2)
        {
            root->right=NULL;
        }
        //建立左子树;
        if(i>a2)
        {
            root->left=build(inorder,a1+1,a1+length,postorder,a2,i-1);
        }
        //建立右子树;
        if(i<b2)
        {
            root->right=build(inorder,a1+length+1,b1,postorder,i+1,b2);
        }
        return root;
    }
    void Display(TreeNode * node)
    {
        if(node==NULL)
            return;
        cout<<node->val<<" ";
        Display(node->left);
        Display(node->right);
    }
};
int main()
{
    vector<int> v1,v2;
    int size;
    cout<<"请输入子树的大小:"<<endl;
    cin>>size;
    int i;
    int temp;
    cout<<"请输入子树的先序序列:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }
    cout<<"请输入二叉树的中序序列:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        v2.push_back(temp);
    }
    Solution s;
    TreeNode * tree=s.buildTree(v1,v2);
    s.Display(tree);
    cout<<endl;
}
