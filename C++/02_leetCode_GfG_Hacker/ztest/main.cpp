
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// class Node
// {
//   public:
//     int val;
//     vector<Node*> neighbors;

//     Node():val{0},neighbors{nullptr}{};
//     Node(int val):val{val},neighbors{nullptr}{};
//     Node(int val, vector<Node*> neighbors):val{val},neighbors{neighbors}{};
// };

class Node
{
 public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

// ================================
vector<Node *> fillAdjList(Node *node)
{
  cout << "----------------\n";
  vector<Node *> ret;
  queue<Node *> toVisit;
  toVisit.push(node);

  while (!toVisit.empty())
  {
    Node *temp = toVisit.front();
    // cout << " in the while working on: " << temp->val << endl;
    toVisit.pop();

    // check if we already added this node to the vector
    bool exist = false;
    for (auto c : ret)
    {
      cout << c->val << "  " << temp->val << " " << boolalpha << (c->val == temp->val) << endl;
      if (c->val == temp->val)
      {
        exist = true;
        // cout << " node exits \n";
        break;
      }
    }

    if (!exist)  // if the node is not in the ret vector
    {
      ret.push_back(temp);
      // cout << " to push new node  \n";
      for (vector<Node *>::iterator it = temp->neighbors.begin(); it != temp->neighbors.end(); it++)
      {
        cout << " are you pushing? " << (*it)->val << endl;
        toVisit.push(*it);
      }
    }
  }
  return ret;
}

// ================================
void printGraph(vector<Node *> adj)
{
  int sizeOfGraph = adj.size();
  if (sizeOfGraph == 0) cout << " a null graph \n";

  cout << "\n size of graph: " << sizeOfGraph << endl;

  // print adj list
  for (vector<Node *>::iterator it = adj.begin(); it != adj.end(); it++)
  {
    cout << " Node: " << (*it)->val << ": ";
    for (vector<Node *>::iterator it2 = (*it)->neighbors.begin(); it2 != (*it)->neighbors.end();
         it2++)
    {
      cout << (*it2)->val << " ";
    }
    cout << endl;
  }
  cout << " ========\n";
}

class Solution
{
 public:
  Node *cloneGraph(Node *node)
  {
    cout << " starts \n";
    if (!node) return nullptr;

    // create the root of graph
    stack<Node *> st;
    map<Node *, Node *> myMap;

    st.push(node);

    Node *newNode = new Node(node->val);
    myMap.insert(pair<Node *, Node *>(node, newNode));

    cout << " while \n";

    while (!st.empty())
    {
      Node *orig = st.top();
      st.pop();
      cout << "orig: " << orig->val << endl;

      for (auto nbr : orig->neighbors)
      {
        if (myMap[nbr] == nullptr)
        {
          st.push(nbr);
          newNode = new Node(nbr->val);
          myMap[nbr] = newNode;
        }
        myMap[orig]->neighbors.push_back(myMap[nbr]);
      }
    }
    return myMap[node];
  }
};

int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);

  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n4);

  n2->neighbors.push_back(n1);
  n2->neighbors.push_back(n3);

  n3->neighbors.push_back(n2);
  n3->neighbors.push_back(n4);

  n4->neighbors.push_back(n1);
  n4->neighbors.push_back(n3);

  cout << " adjacency \n";
  vector<Node *> adj = fillAdjList(n1);
  cout << " print the graph\n";
  printGraph(adj);

  Solution t;
  Node *newGraph = t.cloneGraph(n1);

  vector<Node *> adj2 = fillAdjList(newGraph);
  cout << "\n new graph \n";
  printGraph(adj2);

  cout << "end\n";
  return 0;
}
