struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	stack<int> s1, s2;
    	while (l1) {
    		s1.push(l1->val);
    		l1=l1->next;
		}
		while (l2) {
			s2.push(l2->val);
    		l2=l2->next;
		}
		int sum= 0;
		ListNode *cur = new ListNode(0), *tmp= NULL;
		while (!s1.empty() || !s2.empty()) {
			if (!s1.empty()) {
				sum+= s1.top();
				s1.pop();
			}
			if (!s2.empty()) {
				sum+= s2.top();
				s2.pop();
			}
			cur->val= sum%10;
			sum/= 10;
			tmp = new ListNode(sum);//可能会有增位，所以传sum 
			tmp->next= cur;
			cur= tmp;
		}
		return cur->val? cur : cur->next; //最高位可能为0或1 
    }
};
