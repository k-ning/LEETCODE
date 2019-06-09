//
//  main.cpp
//  Linked List Cycle
//
//  Created by 唧唧歪歪 on 15/5/19.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <map>
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
        //判断当前链表是否含有环;
        bool hasCycle_1(ListNode* head) {
                
                if (head == NULL) {
                        return false;
                }
                ListNode* slow;
                ListNode* fast;
        
                slow = head;
                fast = head;
        
                while (fast != NULL && fast->next != NULL) {
                        fast = fast->next->next;
                        slow = slow->next;
                        
                        if (fast == slow) {
                                return true;
                        }
                }
                return false;
        }
        bool hasCycle_2(ListNode* head) {

                if (head == NULL)
                        return false;
        
                map<ListNode*, int> store;
                ListNode *node = head;
                int cycle = 0;
        
                while (node != NULL) {
                        if (store.find(node) != store.end()) {
                                return true;
                        } else {
                                cycle ++;
                                store[node] = cycle;
                                node = node->next;
                        }
                }
                return false;
        }
};
int main(int argc, const char * argv[]) {
        // insert code here...
        std::cout << "Hello, World!\n";
        return 0;
}
