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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n)
          return head;

        ListNode* fake = new ListNode(0);
        fake->next = head;

        ListNode *p, *p2, *p3, *h1;
        int i;

        for (p = fake, i = 0; i < m-1; i++)
          p = p->next;
        
        h1 = p;
        p = h1->next;
        p2 = p->next;
      
        for (; i < n-1; i++) {
          p3 = p2->next;
          p2->next = p;
          p = p2;
          p2 = p3;
        }

        h1->next->next = p2;
        h1->next = p;
        head = fake->next;

        delete fake;
        return head;
    }
};