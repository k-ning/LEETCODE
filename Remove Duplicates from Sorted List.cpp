//
//  main.cpp
//  Remove Duplicates from Sorted List
//
//  Created by 唧唧歪歪 on 15/5/19.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
#include<map>
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
        if(head==NULL)
            return NULL;
        
        map<int,int> mm;
        ListNode * h=head;
        ListNode * temp=head;
        mm[h->val]=1;
        h=h->next;
        while(h!=NULL)
        {
            //如果在当前的链表中存在当前元素;
            if(mm.find(h->val)!=mm.end())
            {
                temp->next=h->next;
                h=temp->next;
            }
            //若不存在当前元素;
            else
            {
                mm[h->val]=1;
                temp=h;
                h=h->next;
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
