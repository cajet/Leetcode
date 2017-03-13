struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) return NULL;
        ListNode *newHead= new ListNode(0);
        newHead->next= head;
        ListNode *cur= newHead;
        ListNode *fast= head;
        while (fast && fast->next) {
        	int same_val;
        	if (fast->val == fast->next->val) {
        		same_val= fast->val;
        		fast= fast->next->next;
        		while (fast && fast->val == same_val) {
        			fast= fast->next;
				}
				cur->next= fast;
			} else {
				cur= fast;
				fast= fast->next;
			}
		}
		return newHead->next;
    }
};
