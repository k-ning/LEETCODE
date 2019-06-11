#include <iostream>
using namespace std;

/* Cycle the linkedlist for twice times. */
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == NULL || n == 0) {
            return head;
        }
        int length = 0;
        int move = 0;
        ListNode* temp = head;
        
        /* Calculate the length of linkedlist. */
        while (temp != NULL) {
                length++;
                temp = temp->next;
        }
        move = length - n;
        /* If delete the head node, then delete directly. */
        if (move == 0) {
                head = head->next;
                return head;
        }
        
        /* 
         * Locate the node that needs to be deleted and the previous node that needs to            * be deleted.
         */
        ListNode* delete_prev = head;
        ListNode* current_delete = head->next;
        while (move > 1) {
                delete_prev = delete_prev->next;
                current_delete = current_delete->next;
                move--;
        }
        delete_prev->next = current_delete->next;
        current_delete->next = NULL;
        return head;
}
