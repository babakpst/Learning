 

#include "iostream"
#include "memory"

class aa{
private:
  int aa_var;
public:
  void aafunc(){ std::cout << " aa function in aa\n";}
  
  virtual void absfunc()=0;
  virtual void overloadfunc(){ std::cout << " aa overload class\n";}
  
  void speak(){ std::cout << " aa speaks \n";}
};


class bb:public aa{

private:
  int bb_var;
public:
  void bbfunc(){ std::cout << " bb function in bb\n";}
  
  virtual void absfunc(){std::cout << " abs func class\n";}
  virtual void overloadfunc(){ std::cout << " bb overload class\n";}
  
  void speak(){ std::cout << " bb speaks \n";}
};
 
int main(){
std::cout << " starts...\n";

std::cout << "==============\n";
/*
aa aobj;
aobj.aafunc();
aobj.overloadfunct();
aobj.speak();
*/

bb bobj;
bobj.aafunc();
bobj.bbfunc();
bobj.absfunc();
bobj.overloadfunc();
bobj.speak();

std::cout << "==============\n";
std::unique_ptr<aa> paa = std::make_unique<bb>();
paa->aafunc();
//paa->bbfunc();
paa->absfunc();
paa->overloadfunc();
paa->speak();

 
std::cout << " ends\n";
return 0;
}
 
 
 
