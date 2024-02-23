#include <iostream>
#include <string>
#include <vector>

// MenuItem class
class MenuItem
{
 public:
  MenuItem(const std::string &name, const std::string &description, double price)
      : name(name), description(description), price(price)
  {
  }

  std::string getName() const { return name; }
  std::string getDescription() const { return description; }
  double getPrice() const { return price; }

 private:
  std::string name;
  std::string description;
  double price;
};

// Iterator interface
class Iterator
{
 public:
  virtual bool hasNext() = 0;
  virtual MenuItem next() = 0;
};

// Menu interface
class Menu
{
 public:
  virtual Iterator *createIterator() = 0;
};

// CafeMenuIterator class
class CafeMenuIterator : public Iterator
{
 public:
  CafeMenuIterator(std::vector<MenuItem> &items) : items(items), position(0) {}

  bool hasNext()
  {
    if (position >= items.size() || items[position].getName().empty())
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  MenuItem next()
  {
    MenuItem menuItem = items[position];
    position++;
    return menuItem;
  }

 private:
  std::vector<MenuItem> &items;
  int position;
};

// CafeMenu class
class CafeMenu : public Menu
{
 public:
  CafeMenu()
  {
    addItem("Veggie Burger and Air Fries", "Veggie burger on a whole wheat bun, lettuce, tomato, and fries", 3.99);
    addItem("Soup of the day", "A cup of the soup of the day, with a side salad", 3.69);
    addItem("Burrito", "A large burrito, with whole pinto beans, salsa, guacamole", 4.29);
  }

  void addItem(const std::string &name, const std::string &description, double price)
  {
    MenuItem menuItem(name, description, price);
    menuItems.push_back(menuItem);
  }

  Iterator *createIterator() { return new CafeMenuIterator(menuItems); }

 private:
  std::vector<MenuItem> menuItems;
};

int main()
{
  CafeMenu cafeMenu;
  Iterator *iterator = cafeMenu.createIterator();

  while (iterator->hasNext())
  {
    MenuItem menuItem = iterator->next();
    std::cout << menuItem.getName() << ", " << menuItem.getPrice() << " -- " << menuItem.getDescription() << std::endl;
  }

  delete iterator;
  return 0;
}
