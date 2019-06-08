//
//  main.cpp
//  Reverse Linked List II
//
//  Created by 唧唧歪歪 on 15/5/17.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <stack>
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
    ListNode* reverseBetween(ListNode * &head, int m, int n)
    {
        ListNode * temp=head;
        ListNode * te=NULL;
        int tt=0;
        int i=1;
        stack<int> t;
        while(temp!=NULL&&i<m)
        {
            te=temp;
            temp=temp->next;
            i++;
        }
        while(i<=n)
        {
            tt=temp->val;
            t.push(tt);
            temp=temp->next;
            i++;
        }
        if(te!=NULL)
        {
            te->next=NULL;
            while(t.empty()!=true)
            {
                te->next=new ListNode(t.top());
                te=te->next;
                t.pop();
            }
            te->next=temp;
            return head;
        }
        else
        {
            ListNode * ll=new ListNode(t.top());
            head=NULL;
            head=ll;
            t.pop();
            
            while(t.empty()!=true)
            {
                ll->next=new ListNode(t.top());
                t.pop();
                ll=ll->next;
            }
            ll->next=temp;
            return head;
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
int main()
{
    ListNode * head=NULL;
    int size=10;
    int i;
    int temp;
    Solution ss;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        head=ss.Insert(head,temp);
    }
    ss.Display(head);
    ss.reverseBetween(head,2,10);
    ss.Display(head);
}
