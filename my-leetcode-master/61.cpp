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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode *cur=head, *p=head;
        if (head==NULL||head->next==NULL)
          return head;

        //获取链表长度
        while (p!=NULL) {
          size++;
          p = p->next;
        }

        k%=size;
        if (k==0)
          return head;
        //间隔为k
        p=head;
        while (k--)
          p = p->next;
        
        //一个指针为NULL，另一个指针就为倒数第K个
        while (p->next!=NULL) {
          cur = cur->next;
          p = p->next;
        }

        p->next = head;
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};
