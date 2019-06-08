//
//  main.cpp
//  Remove Duplicates from Sorted List II
//
//  Created by 唧唧歪歪 on 15/5/19.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <map>
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
    ListNode* deleteDuplicates(ListNode * &head)
    {
        map<int,int> mm;//表示临时变量;
        map<int,int> v;//表示临时变量;
        ListNode * node=head;
        
        while(node!=NULL)
        {
            if(mm.find(node->val)!=mm.end())
            {
                v[node->val]=1;
            }
            else
            {
                mm[node->val]=1;
            }
            node=node->next;
        }
        
        while(head!=NULL&&v.find(head->val)!=v.end())
        {
            head=head->next;
        }
        if(head==NULL||head->next==NULL)
            return head;
        
        node=head->next;
        ListNode * t=head;
        while(node!=NULL)
        {
            if(v.find(node->val)!=v.end())
            {
                t->next=node->next;
                node=t->next;
            }
            else
            {
                t=t->next;
                node=node->next;
            }
        }
        return head;
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
int main()
{
    ListNode * head=NULL;
    int size=5;
    int i;
    int temp;
    Solution ss;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        head=ss.Insert(head,temp);
    }
    ss.Display(head);
    ss.deleteDuplicates(head);
    ss.Display(head);
}
