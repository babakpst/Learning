 
// babak poursartip
// Aug 6, 2022

/*
disjoint set: union find algorithms/data structure
There is a vector of size nVertices, where each index of the array corresponds to the vertix number and holds the root/parent node. 

There are two algorithms for union find:

- In th quickfind alogrithm (qick find) for Union Find, each element of the array, holds the root of the set that each vertix belongs to. Thus, find complexity if O(1), but union compelxity is O(N).

- In the quickunion find algorithm, each element of the array holds the parent of the vertix. Thus union operation complexity is O(1), but find complexity is O(N).

- Union by rank: Each of these two implementations has its drawback (one O(N) operation). We can use Union by Rank to optimize Quick Union find operation.. The idea is to balance out the height of the tree when we do the union operation. The shorter the height of the tree is, the more efficient the find operation is. 

- To optimize union by rank further (the find operation of course), we can use recurrsion to change the parent of each vertix to the root, in the find process. This is called path compression. 

- rank of each vertix, number of hops to get from the vertix to the root.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// uniodfind: using quick find, each vertix stores 
class quickUnion
{
  private:
    int size;
    std::vector<int> parent;
    
  public:
    quickUnion(){}
    quickUnion(int size):size{size}
    {
      parent.resize(size);
      iota(parent.begin(), parent.end(), 0);
    }    

    void Union(int p, int q)
    {
      int rootp = find(p);
      int rootq = find(q);
      if (rootp != rootq)
        parent[rootq] = rootp;
    }
    
    int find(int p)
    {
      while (p !=parent[p])
      {
        p = parent[p];
      }
      return p;
    }
    
    bool connected(int p, int q)
    {
      return find(p) == find (q);
    }

    void printSet()
    {
      for_each(parent.begin(), parent.end(), [](auto v){std::cout << v << " ";});    
      std::cout << std::endl;
    }

};


// uniodfind: using quick find, each vertix stores 
class quickFind
{
  private: 
    std::vector<int> root;
    int size; // number of vertices in the graph

  public:
    quickFind():size(0){}
    quickFind(int size):size{size}
    {
      root.resize(size);
      // setting the parent of each vertix to iteself
      iota(root.begin(), root.end(),0);
    }

    // find the parent of a vertix
    int find(int vertix)
     {return root[vertix];}
    
    // add two vertices to the same union
    void Union(int p, int q)
    {
      int rootp = find(p);
      int rootq = find(q);
      // setting the parent of q to parent of p
      if (rootp != rootq)
      {
        for(auto it = root.begin(); it != root.end(); it++)
        {
          if (*it == rootq)
            *it = rootp;
        }
        //for_each(root.begin(), root.end(), [&](auto v){
        //std::cout << " here: " << v << " " << rootq << " " << rootp << std::endl;
        //if (v == rootq) 
        //  v = rootp;
        //std::cout << "and  here: " << v << " " << rootq << std::endl;
        //});
      }
    }

    // check if two vertices are in the same union/set, i.e. connected
    bool connected(int p, int q)
    {
      return find(p) == find(q);
    }
    
    void printSet()
    {
      for_each(root.begin(), root.end(), [](auto v){std::cout << v << " ";});    
      std::cout << std::endl;
    }
};

// uniodfind: union by rank
class UnionByRank
{
  private:
    std::vector<int> root;
    std::vector<int> rank;
  public:
    UnionByRank(){}
    UnionByRank(int size):root(size), rank(size,1)
    {
      iota(root.begin(), root.end(), 0);
    }    

    int find(int p)
    {

      /* this is the reqular find, which is of complexity o(N)
      while (p !=root[p])
      {
        p = root[p];
      }
      return p;
      */
      
      // using the recursion, we can compress the tree and set the parent eaual to root each time we find.
      
      if (p == root[p])
        return p;
      
      return root[p] = find(root[p]);
    }

    void Union(int p, int q)
    {
      int rootp = find(p);
      int rootq = find(q);

      // if the roots are the same, they are already in the same set.
      // but if the roots are different, we first compare the height of the
      // vertices, and select the root based on the height of the roots. 
      if (rootp != rootq)
        if (rank[rootp] > rank[rootq])
          root[rootq] = rootp;
        else if (rank[rootq] > rank[rootp])
          root[rootp] = rootq;
        else
        {
          root[rootq] = rootp;
          rank[rootp] +=1;
        }
    }
    

    
    bool connected(int p, int q)
    {
      return find(p) == find (q);
    }

    void printSet()
    {
      for_each(root.begin(), root.end(), [](auto v){std::cout << v << " ";});    
      std::cout << std::endl;
    }
};


//==================================
int main(int argc, char* argv[])
{
  std::cout << " starts here ... \n";

  // quick find ===================
  std::cout << "\n quick find 0\n";
  quickFind qf(10);
  // 1-2-5-6-7 3-8-9 4
  qf.Union(1, 2);
  qf.Union(2, 5);
  qf.Union(5, 6);
  qf.Union(6, 7); 
  qf.Union(3, 8);
  qf.Union(8, 9);
  std::cout << " here is the set: \n";
  qf.printSet();
  std::cout << std::boolalpha <<qf.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha << qf.connected(5, 7) << std::endl;  // true
  std::cout << std::boolalpha << qf.connected(4, 9) << std::endl;  // false

  // 1-2-5-6-7 3-8-9-4
  qf.Union(9, 4);
  std::cout << std::boolalpha << qf.connected(4, 9) << std::endl;  // true


  // quick find ===================
  std::cout << "\n quick find 1\n";
  quickFind qf1(7);
  qf1.Union(0, 1);
  std::cout << " here is the set: \n";
  qf1.printSet();
  qf1.Union(1, 2);
  std::cout << " here is the set: \n";
  qf1.printSet();
  qf1.Union(1, 3);
  std::cout << " here is the set: \n";
  qf1.printSet();
  qf1.Union(4, 5);
  std::cout << " here is the set: \n";
  qf1.printSet();
  qf1.Union(4, 6);
  std::cout << " here is the set: \n";
  qf1.printSet();
  qf1.Union(1, 5);
  std::cout << " here is the set: \n";
  qf1.printSet();  

  std::cout << std::boolalpha <<qf1.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha <<qf1.connected(4, 5) << std::endl;  // true

  // quick union ===================
  std::cout << "\n quick union 0\n";
  quickUnion qu(10);
  // 1-2-5-6-7 3-8-9 4
  qu.Union(1, 2);
  std::cout << " here is the set: \n";
  qu.printSet();
  qu.Union(2, 5);
  std::cout << " here is the set: \n";
  qu.printSet();
  qu.Union(5, 6);
  std::cout << " here is the set: \n";
  qu.printSet();
  qu.Union(6, 7);
  std::cout << " here is the set: \n";
  qu.printSet();
  qu.Union(3, 8);
  std::cout << " here is the set: \n";
  qu.printSet();
  qu.Union(8, 9);
  std::cout << " here is the set: \n";
  qu.printSet();
  std::cout << std::boolalpha <<qu.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha << qu.connected(5, 7) << std::endl;  // true
  std::cout << std::boolalpha << qu.connected(4, 9) << std::endl;  // false

  // 1-2-5-6-7 3-8-9-4
  qu.Union(9, 4);
  std::cout << std::boolalpha << qu.connected(4, 9) << std::endl;  // true

  // quick union ===================
  std::cout << "\n quick union 1\n";
  quickUnion qu1(7);
  qu1.Union(0, 1);
  std::cout << " here is the set: \n";
  qu1.printSet();
  qu1.Union(1, 2);
  std::cout << " here is the set: \n";
  qu1.printSet();
  qu1.Union(1, 3);
  std::cout << " here is the set: \n";
  qu1.printSet();
  qu1.Union(4, 5);
  std::cout << " here is the set: \n";
  qu1.printSet();
  qu1.Union(4, 6);
  std::cout << " here is the set: \n";
  qu1.printSet();
  qu1.Union(1, 5);
  std::cout << " here is the set: \n";
  qu1.printSet();  

  std::cout << std::boolalpha <<qu.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha <<qu.connected(4, 5) << std::endl;  // true
  
  // quick union ===================
  std::cout << "\n quick union 2\n";
  quickUnion qu2(6);
  // 1-2-5-6-7 3-8-9 4
  qu2.Union(1, 0);
  qu2.Union(2, 0);
  qu2.Union(3, 0);
  qu2.Union(4, 0);
  qu2.Union(5, 0);
  std::cout << " here is the set: \n";
  qu2.printSet();
	
  // union by rank ===================
  std::cout << "\n union by rank 0\n";
  UnionByRank ur(10);
  // 1-2-5-6-7 3-8-9 4
  ur.Union(1, 2);
  std::cout << " here is the set: \n";
  ur.printSet();
  ur.Union(2, 5);
  std::cout << " here is the set: \n";
  ur.printSet();
  ur.Union(5, 6);
  std::cout << " here is the set: \n";
  ur.printSet();
  ur.Union(6, 7);
  std::cout << " here is the set: \n";
  ur.printSet();
  ur.Union(3, 8);
  std::cout << " here is the set: \n";
  ur.printSet();
  ur.Union(8, 9);
  std::cout << " here is the set: \n";
  ur.printSet();
  std::cout << std::boolalpha <<ur.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha << ur.connected(5, 7) << std::endl;  // true
  std::cout << std::boolalpha << ur.connected(4, 9) << std::endl;  // false

  // 1-2-5-6-7 3-8-9-4
  ur.Union(9, 4);
  std::cout << std::boolalpha << ur.connected(4, 9) << std::endl;  // true

  std::cout << " done. \n";
  return 0;
}
