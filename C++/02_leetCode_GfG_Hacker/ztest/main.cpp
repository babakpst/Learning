
#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int val) : val{val}, next{nullptr} {}
  ListNode(int val, ListNode *next) : val{val}, next{next} {}
};

// approach 1: two iterations
class Solution
{
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    if (!head) return head;
    ListNode *curr = head;
    int length = 1;

    while (curr->next)
    {
      length++;
      curr = curr->next;
    }
    cout << "length: " << length << endl;
    if (length - n == 0)
    {
      return head->next;
    }

    int node = 1;
    curr = head;
    while (curr->next)
    {
      if (length - n == node)
      {
        ListNode *delNode = curr->next;
        curr->next = curr->next->next;
        delete delNode;
        break;
      }
      else
      {
        curr = curr->next;
        ++node;
      }
    }
    return head;
  }
};

// class Solution
// {
//   public:
//     ListNode * removeNthFromEnd(ListNode * head, int n)
//     {
//       if (!head) return head;
//       ListNode * curr= head, *fastnode = head->next;
//       int length = 1;
//       while(fastnode)
//       {

//         if (fastnode->next)
//         {
//           fastnode=fastnode->next;
//           length++;
//         }
//         if (fastnode->next)
//         {
//           fastnode=fastnode->next;
//           length++;
//         }
//         curr = curr->next;
//       }

//       if (n<length/2)
//       {

//       }

//       return head;
//     }
// };

int main(int argc, char *argv[])
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution sol;
  ListNode *out = sol.removeNthFromEnd(head, 2);

  cout << " answer\n";
  while (out)
  {
    cout << out->val << " ";
    out = out->next;
  }

  cout << "\nend\n";
  return 0;
}
