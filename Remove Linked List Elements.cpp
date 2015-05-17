//
//  main.cpp
//  Remove Linked List Elements
//
//  Created by 唧唧歪歪 on 15/5/17.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==NULL)
        {
            return NULL;
        }
        while(head!=NULL&&head->val==val)
        {
            head=head->next;
        }
        if(head==NULL)
            return NULL;
        ListNode * node=head->next;
        ListNode * h=head;
        while(node!=NULL)
        {
            if(node->val!=val)
            {
                node=node->next;
                h=h->next;
            }
            else
            {
                h->next=node->next;
                node=h->next;
            }
        }
        return head;
    }
};
int main()
{

}
