//
//  main.cpp
//  Reorder List
//
//  Created by 唧唧歪歪 on 15/5/17.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode * & head)
    {
        vector<int> v;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        head=NULL;
        ListNode * l1=NULL;
        ListNode * temp1=NULL;
        ListNode * temp2=NULL;
        
        int i;
        int t=(int)v.size()-1;
        if(t!=-1)
        {
            temp1=new ListNode(v[0]);
            head=temp1;
            l1=head;
        }
        i=1;
        while(i<=(v.size()/2))
        {
            temp1=new ListNode(v[t-i+1]);//首先插入v[i];
            temp2=new ListNode(v[i]);//然后插入元素v[t-i];
            
            if(i==t-i+1)
            {
                l1->next=temp1;
                l1=l1->next;
            }
            else
            {
                //向list中插入第一个元素;
                l1->next=temp1;
                l1=l1->next;
                
                //向list中插入第二个元素;
                l1->next=temp2;
                l1=l1->next;
            }
            i++;
        }
    }
    ListNode * Insert(ListNode * ListHead,int value)
    {
        ListNode * list=new ListNode(value);
        
        if(ListHead==NULL)
        {
            ListHead=list;
            return ListHead;
        }
        ListNode * temp=ListHead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=list;
        
        return ListHead;
    }
    void Display(ListNode * listHead)
    {
        ListNode * head;
        if(listHead==NULL)
        {
            cout<<"链表为空!"<<endl;
            return ;
        }
        head=listHead;
        while(head->next!=NULL)
        {
            cout<<head->val<<"->";
            head=head->next;
        }
        cout<<head->val<<endl;
    }

};
//主函数;
int main()
{
    ListNode * head=NULL;
    int size=4;
    int i;
    int temp;
    Solution ss;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        head=ss.Insert(head,temp);
    }
    ss.Display(head);
    ss.reorderList(head);
    ss.Display(head);
}
