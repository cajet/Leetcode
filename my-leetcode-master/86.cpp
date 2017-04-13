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
    ListNode* partition1(ListNode* head, int x) {
      if (head==NULL || head->next==NULL)
        return head;

      ListNode *h = new ListNode(0);
      h->next = head;
      ListNode *pre = h, *cur = pre->next, *p1=h, *p=p1->next;

      while (p!=NULL) {
        while (cur!=NULL && cur->val<x) {
          pre = cur;
          cur = cur->next;
        }

        if (cur==NULL)
          break;

        p1 = cur;
        p = p1->next;

        while (p!=NULL && p->val >=x) {
          p1 = p;
          p = p->next;
        }

        if (p==NULL)
          break;
        p1->next = p->next;
        pre->next = p;
        p->next = cur;
        pre = p;
        p = p1->next;
      } 

      head = h->next;
      delete h;
      return head;
    }

    ListNode *partition(ListNode *head, int x) {
      ListNode n1(0), n2(0);
      ListNode *p1 = &n1, *p2 = &n2;

      while (head!=NULL) {
        if (head->val<x)
          p1 = (p1->next = head);
        else
          p2 = (p2->next = head);
        head = head->next;
      }

      p1->next = n2.next;
      p2->next = NULL;
      return n1.next;
    }
};
