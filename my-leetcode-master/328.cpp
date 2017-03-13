struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if (head == NULL) return head;
        ListNode *odd= head, *even= head->next, *even_start=  head->next;
        while (even && odd && even->next && odd->next) {
        		odd->next= odd->next->next;
        		odd= odd->next;
        		even->next= even->next->next;
        		even= even->next;
		}
		odd->next= even_start;
		return head;
    }
};
