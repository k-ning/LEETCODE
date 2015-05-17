//
//  main.cpp
//  Reverse Linked List(recursively)
//
//  Created by 唧唧歪歪 on 15/5/17.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
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
    //向链表中插入元素;
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
    //temp指向链表的最后一个元素;
    ListNode* reverseList(ListNode * head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode * temp=head->next;
        head->next=NULL;
        ListNode * tt=reverseList(temp);
        temp->next=head;
        return tt;
    }
    //链表输出;
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
    //ss.Display(head);
    ListNode * list=ss.reverseList(head);
    ss.Display(list);

}
