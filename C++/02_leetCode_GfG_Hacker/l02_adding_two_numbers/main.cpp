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

// =======================
ListNode* createList(int val)
{

  if (val == 0)
    return new ListNode();

  ListNode *head=nullptr, *list=nullptr;
  while (val>0){
    //std::cout << val << std::endl;
    ListNode *temp = new ListNode(val%10);
    val/=10;
    if (!head){
      //std::cout << " head is null \n";
      head = temp;
      list = temp;
      }
    else{
      list->next = temp;
      list = list->next;
      }
  }
  return head;  
}

// =======================
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

// ===============================
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int sum = 0, pos = 0;
      while (l1 != nullptr || l2 != nullptr)
      {
        int d1, d2;
        l1==nullptr ? (d1 = 0,l1):(d1=l1->val, l1=l1->next);
        l2==nullptr ? (d2 = 0,l2):(d2=l2->val, l2=l2->next);
        sum += (d1+d2)*pow(10,pos);
        pos++;
      }
      
      return createAList(sum);
    }

    ListNode* createAList(int val)
    {

      if (val == 0)
        return new ListNode();
        
      ListNode *head=nullptr, *list=nullptr;
      while (val>0){
        //std::cout << val << std::endl;
        ListNode *temp = new ListNode(val%10);
        val/=10;
        if (!head){
          //std::cout << " head is null \n";
          head = temp;
          list = temp;
          }
        else{
          list->next = temp;
          list = list->next;
          }
      }
      return head;  
    }
};


// ===============================
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *head=nullptr, *list=nullptr;
      int c = 0;
      while (l1 != nullptr || l2 != nullptr || c!=0)
      {
        int d1, d2, val;
        l1==nullptr ? (d1 = 0,l1):(d1=l1->val, l1=l1->next);
        l2==nullptr ? (d2 = 0,l2):(d2=l2->val, l2=l2->next);
        int sum = d1+d2+c;
        c = 0;
        sum>=10? (val=sum-10,c++):(val=sum);
        std::cout<< c << std::endl;
        ListNode* temp = new ListNode(val);
        if (!head){
          head = temp;
          list = temp;
        }else{
          list->next = temp;
          list = list->next;
        }
      }
      return head;
    }
};

// ===============================
int main(int argc,char* argv[])
{
  std::cout << "starts ...\n";

  if (argc<2){
    std::cout << " insert two ints \n";
    return -1;
    }

  std::cout << std::atoi(argv[1]) << " "  << std::atoi(argv[2]) << std::endl;
  ListNode *num1 = createList(std::atoi(argv[1]));
  ListNode *num2 = createList(std::atoi(argv[2]));
 
  /*
  ListNode *num1 = new ListNode(2);
  add(num1,4);
  add(num1,3);

  ListNode *num2 = new ListNode(5);
  add(num2,6);
  add(num2,4);

  printList(num1);
  printList(num2);
  */
  
  printList(num1);
  printList(num2); 
 
  Solution t;
  ListNode *res = t.addTwoNumbers(num1,num2);
  std::cout << "\n answer \n";
  printList(res);

  std::cout << "end ...\n";
  return 0;
}

//9999999991



