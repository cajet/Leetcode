struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum= 0;
		ListNode *cur= new ListNode(0), *tmp= NULL, *head= cur; 
		while (l1||l2) {
			if (l1) {
				sum+= l1->val;
				l1= l1->next; 
			}
			if (l2) {
				sum+= l2->val;
				l2= l2->next; 
			}
			cur->val= sum%10;
			sum/= 10; 
			if (sum == 0 && !l1 && !l2) break; //�����һ��Ϊ0��ʱ�򣬲��ü���������
			tmp= new ListNode(sum);
			cur->next= tmp;
			cur= tmp; 
		}
		return head;
    }
};
