#include <iostream>
using namespace std;
/*
 * test case: 
 * [5] [5]
 */

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp_sum = 0;
        int carry = 0;
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        ListNode *temp = l1;
        ListNode *temp1 = l2;
        ListNode *head;
        ListNode *tmp = new ListNode(0);
        head = tmp;
        
        while (temp != NULL || temp1 != NULL) {
                tmp_sum += carry;
            
                if (temp != NULL)
                        tmp_sum += temp->val;
                if (temp1 != NULL)
                        tmp_sum += temp1->val;
            
                if (tmp_sum >= 10) {
                        tmp_sum = tmp_sum - 10;
                        carry = 1;
                } else {
                        carry = 0;
                }
                tmp->val = tmp_sum;

                if (temp != NULL)
                        temp = temp->next;
                if (temp1 != NULL)
                        temp1 = temp1->next;
                
                if (temp == NULL && temp1 == NULL && carry == 0) {
                        return head;
                } else if (temp == NULL && temp1 == NULL && carry != 0) {
                        ListNode *tmp1 = new ListNode(carry);
                        tmp->next = tmp1;
                        tmp = tmp->next;
                        return head;
                }

                ListNode *tmp1 = new ListNode(0);
                tmp->next = tmp1;
                tmp = tmp->next;
                tmp_sum = 0;
        }
        return head;
}
int main () {
        return 0;
}
