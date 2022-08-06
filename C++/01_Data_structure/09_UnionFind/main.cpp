  
  
// babak poursartip
// Aug 6, 2022

/*
union find algorithms/data structure

quickfind qick find


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// uniodfind
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



//==================================
int main(int argc, char* argv[])
{
  std::cout << " starts here ... \n";

  quickFind qf(10);
  // 1-2-5-6-7 3-8-9 4
  qf.Union(1, 2);
  std::cout << " here is the set: \n";
  qf.printSet();
  qf.Union(2, 5);
  std::cout << " here is the set: \n";
  qf.printSet();
  qf.Union(5, 6);
  std::cout << " here is the set: \n";
  qf.printSet();
  qf.Union(6, 7);
  std::cout << " here is the set: \n";
  qf.printSet();
  qf.Union(3, 8);
  std::cout << " here is the set: \n";
  qf.printSet();
  qf.Union(8, 9);
  std::cout << " here is the set: \n";
  qf.printSet();
  std::cout << std::boolalpha <<qf.connected(1, 5) << std::endl;  // true
  std::cout << std::boolalpha << qf.connected(5, 7) << std::endl;  // true
  std::cout << std::boolalpha << qf.connected(4, 9) << std::endl;  // false

  // 1-2-5-6-7 3-8-9-4
  qf.Union(9, 4);
  std::cout << std::boolalpha << qf.connected(4, 9) << std::endl;  // true

  std::cout << " done. \n";
  return 0;
}
