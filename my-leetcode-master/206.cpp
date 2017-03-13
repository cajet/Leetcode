struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p= head;
        ListNode* temp= NULL;
        while (head) {
        	p= head->next;
        	head->next = temp;
        	temp= head;
        	head= p;
		}
        return temp;
    }
};
