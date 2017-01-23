#include <iostream>

#include "helper.hpp"

using namespace std;

typedef struct helper::ListNode ListNode;

ListNode * addTwoNumbers(ListNode *, ListNode *);
void printListNode (ListNode *);
ListNode * weirdTest (ListNode *);	

int main(){
	ListNode l1(5);
	ListNode l2(4);
	ListNode l3(2);

	ListNode l4(1);
	ListNode l5(7);
	ListNode l6(3);

	l1.next = &l2;
	l2.next = &l3;

	l4.next = &l5;
	l5.next = &l6;

	printListNode(&l1);
	printListNode(&l4);	
	
	ListNode * l7 = addTwoNumbers(&l1, &l4);
	printListNode(l7);
        return 0;
}

ListNode * addTwoNumbers(ListNode * l1, ListNode * l2){
	ListNode * dummyHead = new ListNode(0);
	ListNode * p = l1;
	ListNode * q = l2; 
	ListNode * curr = dummyHead;
	int carry = 0;
	while (p != NULL || q != NULL){
		int x = (p != NULL) ? p->val : 0;
		int y = (q != NULL) ? q->val : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		if (p != NULL){
			p = p->next;
		}
		if (q != NULL){
			q = q->next;
		}
	}
	if (carry > 0){
		curr->next = new ListNode(carry);
	}
	return dummyHead->next;	
}

void printListNode (ListNode * l){
	int i = 0;
	while (l){
		cout << l->val << " -> ";
		l = l->next;
		i++;
	}
	cout << std::endl;
}

