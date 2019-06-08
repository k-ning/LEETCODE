//
//  main.cpp
//  Insertion Sort List
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
    ListNode(int x):val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode * MakeList(ListNode * head,int value)
    {
        ListNode * temp=new ListNode(value);
        if(head==NULL)
        {
            return temp;
        }
        
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    
    ListNode* insertionSortList(ListNode* head)
    {
        if(head==NULL)
            return head;
        
        ListNode * temp=head;//表示临时变量;
        ListNode * list=NULL;//表示一个链表;
        while(temp!=NULL)
        {
            list=insert(list,temp->val);
            temp=temp->next;
        }
        delete head;
        head=list;
        return head;
    }
    
    ListNode * insert(ListNode * head,int value)
    {
        ListNode * t=new ListNode(value);
        
        if(head==NULL)
            return t;
        
        ListNode * temp=head;
        if(head->val>value)
        {
            t->next=head;
            head=t;
            temp=head;
            return head;
        }
        while(temp->next!=NULL)
        {
            if((temp->val<=value)&&(temp->next->val>value))
            {
                t->next=temp->next;
                temp->next=t;
                return head;
            }
            else
                temp=temp->next;
        }
        temp->next=t;
        return head;
    }
    
    void Show(ListNode * head)
    {
        ListNode * temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
//主函数;
int main()
{
    int size;
    cout<<"请输入一个整数:"<<endl;
    cin>>size;
    int i;
    int temp;//表示临时变量;
    vector<int> v;
    ListNode * head=NULL;
    Solution ss;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        head=ss.MakeList(head,temp);
    }
    ss.Show(head);
    head=ss.insertionSortList(head);
    ss.Show(head);
}

