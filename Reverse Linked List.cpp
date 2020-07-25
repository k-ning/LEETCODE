//
//  main.cpp
//  Reverse Linked List
//
//  Created by 唧唧歪歪 on 15/5/17.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//结构体;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight (ListNode* head, int k) {
        if (k == 0 || head == NULL)
                return head;
        
        int length = 0, t = 0;
        int i = 1;
        ListNode* node = head;
        ListNode* current = head;
        ListNode* next = current->next;
        
        while (node != NULL) {
                length ++;
                node = node->next;
        }
        if (k % length == 0) {
                return head;
        }
        if (k / length == 0) 
                t = length - k;
        else
                t = length - (k - k/length * length);
        while (i < t) {
                current = current->next;
                next = current->next;
                i++;
        }
        current->next = NULL;
        
        ListNode* head1 = next;
        ListNode* tail = head1;
        
        while (tail->next != NULL) {
                tail = tail->next;
        }
        tail->next = head;
        return head1;
}

class Solution
{
public:
    ListNode* reverseList (ListNode * head) {

        ListNode * tt = NULL;
        if (head == NULL)
            return tt;
        
        tt = head;//赋予头指针;
        ListNode * temp = NULL;
        ListNode * list = NULL;

        while (tt != NULL) {
            temp = new ListNode (tt->val);
            list = Insert (list,temp);
            tt = tt->next;
        }
        delete head;
        head = list;
        return head;
    }
    
    //向链表中插入结点元素temp;
    ListNode * Insert (ListNode * head, ListNode * temp) {

        if (head == NULL)
            return temp;
        temp->next = head;
        head = temp;
        return head;
    }
};
int main()
{

}
