#include <iostream>
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
        
	ListNode* head = new ListNode(0);
	ListNode* temp = head;
        
	while (l1 && l2) {
		if (l1->val > l2->val) {
			temp->next = l2;
			temp = temp->next;

			l2 = l2->next;
		} else if (l1->val < l2->val) {
			temp->next = l1;
			temp = temp->next;

			l1 = l1->next;
		} else {
			temp->next = l1;
			temp = l1;
			l1 = l1->next;

			temp->next = l2;
			temp = temp->next;
			l2 = l2->next;
		}
	}
	// Make good use of trinomial operators.
	temp->next = (l1 == NULL) ? l2 : l1;
	return head->next;
}
