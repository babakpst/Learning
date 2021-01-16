#include "stdafx.h"

template <typename T> class INotifyPropertyChanged
{
public:
  signal<void(const T*, string)> PropertyChanged;
};

class Player : public INotifyPropertyChanged<Player>
{
  int numberOfGoals;
  int age;
public:
  __declspec(property(get = GetAge, put = PutAge)) int Age;

  int GetAge() const { return age; }

  void PutAge(int value)
  {
    if (value == age) return;
    PropertyChanged(this, string("Age"));
    age = value;
  }

  string name;
  Player(string name) : name(name)
  {
    numberOfGoals = 0;
  }
  typedef signal<void(string, int)> SignalType;
  SignalType Scores;
  void Score()
  {
    numberOfGoals++;
    Scores(name, numberOfGoals);
  }
};

class Coach
{
public:
  void PlayerScored(string name)
  {
    cout << "well done, " << name << endl;
  }
};

#include "FundamentalsAndCustom.h"










template <typename T> struct average
{
  typedef T result_type;

  template <typename II> T operator()(II first, II last) const
  {
    if (first == last) return T();
    float sum = 0.0;
    int count = 0;
    while (first != last)
    {
      sum += *first++;
      count++;
    }
    return sum / count;
  }
};

void f()
{
  signal<float(float, float), average<float>> s;

  s.connect([](float a, float b) { return a + b; });
  s.connect([](float a, float b) { return a * b; });

  cout << s(3, 4) << endl;
}

int main(int argc, char* argv[])
{
  Player p("John");

  p.PropertyChanged.connect(
    [](const Player* p, string propName)
    {
      cout << p->name << "'s " << propName << 
        " has changed " << endl;
  });

  p.Age = 25;

/*
  signal<void(int)> values;

  values.connect_extended(
    [](const connection& conn, int value)
  {
    static int count = 0;
    if (++count > 5)
      conn.disconnect();
    else
      cout << "got a value of " << value << endl;
  });

  srand((unsigned)time(nullptr));
  for (size_t i = 0; i < 100; i++)
  {
    values(rand());
  }*/
  

  getchar();
	return 0;
}

