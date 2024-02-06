
// Babak Poursartip
// credit goes to the linkedin course: design pattern creational

#include <cstring>
#include <iostream>

// =======================================
// Base Entree class
class Entree
{
 protected:
  char _entree[10];

 public:
  const char *getEntree() { return _entree; }
};

// =======================================
// Derived Buger class
class Burger : public Entree
{
 public:
  Burger()
  {
    printf("\n Grill burger patty, add tomatoes and place them in a bun");
    strcpy(_entree, "hamburger");
  }
};

// =======================================
// Derived Hotdog class
class Hotdog : public Entree
{
 public:
  Hotdog()
  {
    printf("\n Cook sausage and place it in a bun");
    strcpy(_entree, "hotdog");
  }
};

// =======================================
// Base Side class
class Side
{
 protected:
  char _side[10];

 public:
  char *getSide() { return _side; }
};

// =======================================
// Derived Fries class
class Fries : public Side
{
 public:
  Fries()
  {
    printf("\n Fry and season potatoes");
    strcpy(_side, "fries");
  }
};

// =======================================
// Derived Salad class
class Salad : public Side
{
 public:
  Salad()
  {
    printf("\n Toss greens and dressing together");
    strcpy(_side, "salad");
  }
};

// =======================================
class Drink
{
 protected:
  char _drink[10];

 public:
  Drink()
  {
    printf("\n Fill cup with soda \n");
    strcpy(_drink, "soda");
  }
  char *getDrink() { return _drink; }
};

// =======================================
// Complex MealCombo object that contains an Entree, a Side and a Drink object
class MealCombo
{
 private:
  Entree *entree;
  Side *side;
  Drink *drink;

  char _bag[100];

 public:
  MealCombo(const char *type) { sprintf(_bag, "\n %s meal combo:", type); }
  void setEntree(Entree *e) { entree = e; }
  void setSide(Side *s) { side = s; }
  void setDrink(Drink *d) { drink = d; }
  const char *openMealBag()
  {
    sprintf(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
    return _bag;
  }
};

// =======================================
// Base Builder
class MealBuilder
{
 protected:
  MealCombo *_meal;

 public:
  virtual void cookEntree() = 0;
  virtual void cookSide() = 0;
  virtual void fillDrink() = 0;

  MealCombo *getMeal() { return _meal; }
};

// =======================================
// Concrete Builder for a Burger Meal which has a burger, fries and a drink
class BurgerMeal : public MealBuilder
{
 public:
  BurgerMeal() { _meal = new MealCombo("Burger"); }
  void cookEntree()
  {
    Burger *burger = new Burger;
    _meal->setEntree(burger);
  }
  void cookSide()
  {
    Fries *potato = new Fries;
    _meal->setSide(potato);
  }
  void fillDrink()
  {
    Drink *drink = new Drink;
    _meal->setDrink(drink);
  }
};

// =======================================
// Concrete Builder for a Hotdog Meal which has a hotdog, salad and a drink
class HotdogMeal : public MealBuilder
{
 public:
  HotdogMeal() { _meal = new MealCombo("Hotdog"); }
  void cookEntree()
  {
    Hotdog *hotdog = new Hotdog;
    _meal->setEntree(hotdog);
  }
  void cookSide()
  {
    Salad *caesar = new Salad;
    _meal->setSide(caesar);
  }
  void fillDrink()
  {
    Drink *drink = new Drink;
    _meal->setDrink(drink);
  }
};

int main()
{
  int choice;

  // Prompt user for their meal choice
  printf("Select a meal:  \n");
  printf("1: Hamburger Meal \n");
  printf("2: Hotdog Meal \n");
  printf("Selection: ");
  std::cin >> choice;
  printf("\n");

  // Instantiate the apporpriate builder based on user input
  // MealBuilder *cook = new MealBuilder;
  MealBuilder *cook;
  MealCombo *meal;

  switch (choice)
  {
    case 1:
      cook = new BurgerMeal;
      break;
    case 2:
      cook = new HotdogMeal;
      break;
    default:
      puts("wrong choice");
      cook = NULL;
      break;
  }

  printf("Making selected meal");

  // Build the complex object
  cook->cookEntree();
  cook->cookSide();
  cook->fillDrink();
  meal = cook->getMeal();
  printf(" This is my bag:\n %s \n", meal->openMealBag());
}
