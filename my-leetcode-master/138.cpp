/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList1(RandomListNode *head) {
      if (head==NULL)
        return NULL;
      RandomListNode *ans = new RandomListNode(head->label), *cur=head, *p=ans;
      vector<RandomListNode*>::iterator tmp;
      int n;
      //<origin, new>
      vector<RandomListNode*> origin;
      vector<RandomListNode*> newone;
      origin.push_back(head);
      newone.push_back(ans);

      while (cur!=NULL) {
        //random不为空
        if (cur->random!=NULL) {
          tmp = find(origin.begin(), origin.end(), cur->random);
          //未访问
          if (tmp==origin.end()) {
            origin.push_back(cur->random);
            p->random = new RandomListNode(cur->random->label);
            newone.push_back(p->random);
          //已经访问
          } else {
            p->random = newone[tmp-origin.begin()];
          }
        }

        if (cur->next!=NULL) {
          tmp = find(origin.begin(), origin.end(), cur->next);
          //未访问
          if (tmp==origin.end()) {
            origin.push_back(cur->next);
            p->next = new RandomListNode(cur->next->label);
            newone.push_back(p->next);
          //已经访问
          } else {
            p->next = newone[tmp-origin.begin()];
          }
        }

        p = p->next;
        cur = cur->next;
      }

      return ans;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
      if (head==NULL)
        return NULL;
      RandomListNode *l1, *l2;
      //创建节点
      for (l1=head; l1!=NULL; l1=l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
      }

      //设置random
      for (l1=head; l1!=NULL; l1=l1->next->next) {
        l2 = l1->next;
        if (l1->random!=NULL)
          l2->random = l1->random->next;
      }

      //拆分链表
      RandomListNode *newhead=head->next;
      for (l1=head; l1!=NULL; l1=l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next!=NULL )
          l2->next = l2->next->next;
      }

      return newhead;
    }
};


