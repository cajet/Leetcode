/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k<=1 || head==NULL||head->next==NULL)
        return head;
      ListNode *h=new ListNode(0), *front=h, *end=head, *p1, *p2, *p3;
      h->next = head;
      int i;
      while (end!=NULL) {
        for (i = 0; i < k&&end!=NULL; i++) {
          end = end->next;
        }

        if (i<k)
          return h->next;

        p1 = front->next;
        p2 = p1->next;
        while (p2!=end) {
          p3 = p2->next;
          p2->next = p1;
          p1 = p2;
          p2 = p3;
        }
        p3 = front->next;
        p3->next = end;
        front->next = p1;
        front = p3;
        end = p2;
      }
      return h->next;
    }
};