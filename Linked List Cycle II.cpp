//
//  main.cpp
//  Linked List Cycle II
//
//  Created by 唧唧歪歪 on 15/5/19.
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
        ListNode *detectCycle(ListNode *head) {

                if (head == NULL)
                        return NULL;

                ListNode * slow = head;
                ListNode * quick = head;
        
                while (quick != NULL && quick->next != NULL) {
                        slow = slow->next;
                        quick = quick->next->next;
                        if (quick == slow) {
                                break;
                        }
                }

                if (quick == NULL || quick->next == NULL) {
                        return NULL;
                }
                
                slow = head;
                while (slow != quick) {
                        slow = slow->next;
                        quick = quick->next;
                }
                return slow;
        }
};
int main()
{

}
