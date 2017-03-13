// 证明：  如下是两条交叉的单向链表，上一半长度是a,下一半长度是b，交叉部分是c
//         a
//      ---------\        c
//                \—————————————————
//          b     /
//      ---------/
//      L1和L2长度不一样，每个人走完一条单链分别是a+c和b+c
//      走完后走另一条，此时两个人会相遇，而且此时下标都是a+b+c，也就是交叉点


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *a= headA, *b= headB;
      if (a== NULL || b== NULL) return NULL;
      while (a!=b) {
        a = a->next;
        b = b->next;
        //此时如果是两个没有相交的链表，就会一起走了a+b+2c
        //到达NULL，返回NULL
        if (a== b) return a;

        if (a== NULL) a = headB;
        if (b== NULL) b = headA;
      }
      return a;
    }
};
