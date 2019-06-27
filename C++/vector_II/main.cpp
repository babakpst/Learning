
// constructing vectors
#include <iostream>
#include <vector>
#include <forward_list>

//=================================================================================================
void func_check( std::vector<int> &MyVec, int &Value, int &node ){


  std::cout << " node:" << node << " value:" << Value << std::endl;
  //MyVec[node] = 10;
  MyVec[node] = Value;

  Value++;
  node--;

  MyVec[node] = Value;

}


//=================================================================================================
void forwardList_func(std::forward_list<int> *&MyList, int SizeOfVector){

  for (int i = 0; i < SizeOfVector; ++i){
    std::cout << " inside the funciton = list no. " << i << std::endl;
    for (std::forward_list<int>:: iterator itr=MyList[i].begin(); itr != MyList[i].end(); ++itr){
      std::cout << " my list " << *itr << std::endl;
    };
  };

}



//=================================================================================================
int main ()
{
  // constructors used in the same order as described above:
  int const SizeOfVector=15;
  std::vector<int> MyVec(SizeOfVector);


   int Value;
  int node;
  
  node = 3;
  Value = 5;

  MyVec[node] = Value;


    for (std::vector<int> :: iterator itr=MyVec.begin(); itr != MyVec.end(); ++itr){
      std::cout << "MyVec[] " << *itr << std::endl;
    };

  node = 5;

  func_check(MyVec, Value, node);


  std::cout << " after the function" << std::endl;
    for (std::vector<int> :: iterator itr=MyVec.begin(); itr != MyVec.end(); ++itr){
      std::cout << "MyVec[] " << *itr << std::endl;
    };


  //===============================================================================================
  //std::forward_list<int> MyList(SizeOfVector);
  std::forward_list<int> *MyList= new std::forward_list<int>[SizeOfVector];

  for (int i=0; i < SizeOfVector; ++i){
    for (int j= 0; j < 3; ++j){
      MyList[i].push_front(j);
    };
  };

  for (int i = 0; i < SizeOfVector; ++i){
    std::cout << "list no. " << i << std::endl;
    for (std::forward_list<int>:: iterator itr=MyList[i].begin(); itr != MyList[i].end(); ++itr){
      std::cout << " my list " << *itr << std::endl;
    };
  };

  forwardList_func(MyList, SizeOfVector);
  //MyList[0] = 10;

  std::cout << " new values"  << std::endl;
  for (int i = 0; i < SizeOfVector; ++i){
    for (std::forward_list<int>:: iterator itr=MyList[i].begin(); itr != MyList[i].end(); ++itr){
      std::cout << " my list " << *itr << std::endl;
    };
  };


  return 0;
}
