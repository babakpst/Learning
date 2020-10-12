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
      ListNode *la=headA, *lb=headB;
      int lenA=1, lenB=1;
      if (headA == nullptr || headB == nullptr) return nullptr;
      while(la->next) {la = la->next;lenA++;}
      while(lb->next) {lb = lb->next;lenB++;}
      if (la != lb) return nullptr;
      int len;
      // la is the longer list, lb is the shorter
      (lenA > lenB)? (la=headA, lb=headB, len=lenB):(la=headB,lb=headA,len=lenA);
      for (int i = 0; i < abs(lenA-lenB);++i)la = la->next;
      for (int i = 0; i < len;++i){ 
        if (la==lb) break;
        else{
          la=la->next;lb=lb->next;
        }
      }
      return la;
    }
};
