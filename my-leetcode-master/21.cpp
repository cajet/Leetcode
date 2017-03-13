#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
      	else if (l2 == NULL) return l1;
        ListNode *head, *p;
        if (l1->val< l2->val) {
        	head= l1;
        	l1= l1->next;
		} else {
			head= l2;
        	l2= l2->next;
		}
      	p= head;
      	while (l1&&l2) {
      		if (l1->val < l2->val) {
      			p->next= l1;
      			l1= l1->next;
      			p= p->next;
			  } else {
			  	p->next= l2;
			  	l2= l2->next;
			  	p= p->next;
			  }  
		}
		if (l1) {
			p->next= l1;
		} else {
			p->next= l2;
		}
		return head;
}
