#include <iostream>
using namespace std;

ListNode* reverseList(ListNode* head) {

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
        
	ListNode* current = head;
	ListNode* currentNext = head->next;
	ListNode* prev = NULL;
        
	while (currentNext != NULL) {
		current->next = prev;
		prev = current;
		current = currentNext;
		currentNext = current->next;
        }
	current->next = prev;
	return current;
}