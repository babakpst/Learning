
// Jul 24, 2022

/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the
first node with val == 1, the second node with val == 2, and so on. The graph is represented in the
test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list
describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given
node as a reference to the cloned graph.


*/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
// ================================
// Definition for a Node.

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
      // cout << c->val << "  " << temp->val << endl;
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
        // cout << " are you pushing? " <<(*it)->val << endl;
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

  cout << " size of graph: " << sizeOfGraph << endl;

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
}

// ================================
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {

//     if (node == nullptr)
//       return nullptr;

//     vector<Node *>  ret;
//     queue<Node*> toVisit;
//     toVisit.push(node);

//     while(!toVisit.empty())
//     {
//       Node *temp = toVisit.front();
//       //cout << " in the while working on: " << temp->val << endl;
//       toVisit.pop();

//       // check if we already added this node to the vector
//       bool exist = false;
//       for (auto c : ret)
//       {
//         //cout << c->val << "  " << temp->val << endl;
//         if (c->val == temp->val)
//         {
//           exist = true;
//           //cout << " node exits \n";
//           break;
//         }
//       }

//       if (!exist) // if the node is not in the ret vector
//       {
//         ret.push_back(temp);
//         //cout << " to push new node  \n";
//         for (vector<Node*>::iterator it = temp->neighbors.begin(); it!=temp->neighbors.end();
//         it++)
//         {
//           //cout << " are you pushing? " <<(*it)->val << endl;
//           toVisit.push(*it);
//         }

//       }
//     }

//     vector<Node*> out;
//     for (vector<Node*>::iterator it = ret.begin(); it!=ret.end(); it++)
//     {
//       out.push_back(new Node{(*it)->val}) ;
//     }

//     Node * temp;
//     for (int i = 0; i<ret.size(); i++)
//     {
//       temp = ret[i];
//       for (int j = 0; j<temp->neighbors.size(); j++)
//       {
//         int nNum = temp->neighbors[j]->val;
//         for (int k=0;k<out.size(); k++)
//         {
//           if(nNum == out[k]->val)
//           {
//             nNum = k;
//             break;
//           }
//         }
//         out[i]->neighbors.push_back(out[nNum]);
//       }
//     }

//     return out[0];
//     }
// };

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

// ================================
int main(int argc, char *argv[])
{
  cout << " starts ... \n";

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

  vector<Node *> adj = fillAdjList(n1);
  printGraph(adj);

  Solution t;
  Node *newGraph = t.cloneGraph(n1);

  vector<Node *> adj2 = fillAdjList(newGraph);
  cout << " new graph \n";
  printGraph(adj2);

  cout << " done.  \n";
  return 0;
}
