// ֤����  ��������������ĵ���������һ�볤����a,��һ�볤����b�����沿����c
//         a
//      ---------\        c
//                \����������������������������������
//          b     /
//      ---------/
//      L1��L2���Ȳ�һ����ÿ��������һ�������ֱ���a+c��b+c
//      ���������һ������ʱ�����˻����������Ҵ�ʱ�±궼��a+b+c��Ҳ���ǽ����


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
        //��ʱ���������û���ཻ�������ͻ�һ������a+b+2c
        //����NULL������NULL
        if (a== b) return a;

        if (a== NULL) a = headB;
        if (b== NULL) b = headA;
      }
      return a;
    }
};
