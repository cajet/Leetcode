struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
	public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head!= NULL && head->val == val) {
        	head= head->next;
		}
		if (head == NULL) return NULL;
		ListNode *q= head;
		ListNode *p= head->next;
		while (p) {
			if (p->val == val) {
				q->next= p->next;
				p= p->next;
			} else {
				q= p;
				p= p->next;
			}
		}
		return head;
    }
};
