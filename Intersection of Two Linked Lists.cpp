//
//  main.cpp
//  Intersection of Two Linked Lists
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
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==NULL||headB==NULL)
            return NULL;
        
        //1.连接两个单链表;
        ListNode * head=headA;
        
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=headB;//纪录下当前链表连接的节结点;
        
        //2.查找当前链表是否存在碰撞点(是否为环);
        ListNode * slow=headA;//表示慢结点;
        ListNode * quick=headA;//表示快结点;
        
        while(quick!=NULL&&quick->next!=NULL&&quick->next->next!=NULL)
        {
            slow=slow->next;
            quick=quick->next->next;
            
            if(slow==quick)
            {
                break;
            }
        }
        if(quick==NULL||quick->next==NULL||quick->next->next==NULL)
        {
            head->next=NULL;
            return NULL;
        }
        
        //3.若有碰撞点,则找到两个链表的连接点;
        ListNode * l1=headA;
        while(l1!=slow)
        {
            l1=l1->next;
            slow=slow->next;
        }
        
        //4.断开连接，同时返回链接点;
        head->next=NULL;
        return l1;
    }
};
int main()
{
    

}
