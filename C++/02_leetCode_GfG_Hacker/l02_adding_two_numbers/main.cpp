//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>
#include <cmath>


struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void add(ListNode *head, int val)
{
  ListNode *temp = head;
  
  while (temp->next != nullptr)
    temp = temp->next;
  
  temp->next = new ListNode(val);
}

void printList(ListNode *temp)
{
  std::cout << " list is: \n" ;
  if (temp==nullptr)
    return;

  while (temp->next != nullptr){
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << temp->val << " ";
  std::cout << "\n";

}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    //printList(l1);
    //printList(l2);
    int sum = 0;
    int pos = 0;
    while (l1->next != nullptr && l2->next != nullptr)
    {
      sum += (l1->val+l2->val)*pow(10,pos);
      l1=l1->next,l2=l2->next;
      std::cout << sum << std::endl;
      pos++;
    }
    
    ListNode *res = new ListNode();
    ListNode *temp=res;
    while (sum/10!=0)
    {
      temp->val = sum%10;
      ListNode *temp2 = new ListNode();
      temp->next=temp2;
      temp = temp->next;
      sum = sum/10;
    }
    
    
    return res;
    }
};


int main()
{
  std::cout << "starts ...\n";

  ListNode *num1 = new ListNode(2);
  add(num1,4);
  add(num1,3);

  ListNode *num2 = new ListNode(5);
  add(num2,6);
  add(num2,4);

  printList(num1);
  printList(num2);

  Solution t;
  ListNode *res = t.addTwoNumbers(num1,num2);
  printList(res);

  std::cout << "end ...\n";
  return 0;
}
