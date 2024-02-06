
// Babak Poursartip
// from the design pattern course in linkedin

// 08/10/2020

#include <cstring>
#include <iostream>

// base entree class
class entree
{
 protected:
  char _entree[10];

 public:
  const char *getEntree() { return _entree; }
};

// base side class
class side
{
 protected:
  char _side[10];

 public:
  char *getSide() { return _side; }
};

// base drink class
class drink
{
 protected:
  char _drink[10];

 public:
  drink()
  {
    printf(" \n Fill the cup with soda, please \n");
    strcpy(_drink, "soda");
  }
  char *getDrink() { return _drink; }
};

// combo meal class
class comboMeal
{
 private:
  entree *myEntree;
  side *mySide;
  drink *myDrink;
  char _bag[100];

 public:
  comboMeal(const char *type)
  {
    sprintf(_bag, "/n %s meal combo:", type);
    printf("bag constructor: %s ", _bag);
  }

  void setEntree(entree *e) { myEntree = e; }
  void setSide(side *s) { mySide = s; }
  void setDrink(drink *d) { myDrink = d; }

  const char *openMealBag()
  {
    sprintf(_bag, "%s %s, %s, %s", _bag, myEntree->getEntree(), mySide->getSide(), myDrink->getDrink());

    return _bag;
  }
};

// =============================================================================
int main()
{
  puts("\n The code starts here ...\n");

  comboMeal *bob = new comboMeal("burger");
  const char *bag = bob->openMealBag();
  printf("bag constructor: %s ", bag);
  puts("\n Successfully terminated. \n");
  return 0;
}

// complex object that contains entree, side, and drink objects
