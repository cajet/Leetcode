struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode *cur= head->next, *pre= head;
        ListNode *newHead= cur, *temp= NULL; 
		while (cur)  {
			temp= cur->next; 
			cur->next= pre;
			if (temp && temp->next) pre->next= temp->next;
			else {
				pre->next= temp;
				break;
			}
			pre= temp;
			cur= pre->next; 
		}
		return newHead;
    }
};
