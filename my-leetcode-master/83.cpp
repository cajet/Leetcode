struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) return NULL;
        ListNode *fast= head, *slow= head;
        fast= fast->next;
        while (fast) {
        	if (fast->val == slow->val) {
        		slow->next= fast->next;
        		fast= fast->next;
			} else {
				fast= fast->next;
				slow= slow->next;
			}
		}
		return head;
    }
};
