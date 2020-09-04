#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//=====================================
class Spell {
private:
  string scrollName;

public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() { return scrollName; }
};

//=====================================
class Fireball : public Spell {
private:
  int power;

public:
  Fireball(int power) : power(power) {}
  void revealFirepower() { cout << "Fireball: " << power << endl; }
};

//=====================================
class Frostbite : public Spell {
private:
  int power;

public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

//=====================================
class Thunderstorm : public Spell {
private:
  int power;

public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

//=====================================
class Waterbolt : public Spell {
private:
  int power;

public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

//=====================================
class SpellJournal {
public:
  static string journal;
  static string read() { return journal; }
};
string SpellJournal::journal = "";

//=====================================
void counterspell(Spell *spell) { /* Enter your code here */
  cout << typeid(*spell).name() << endl;
}

//=====================================
class Wizard {
public:
  Spell *cast(ifstream &in) {
    Spell *spell;
    string s;
    in >> s;
    int power;
    in >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

//=====================================
int main() {
  ifstream in("magic.txt");

  int T;
  in >> T;
  Wizard Arawn;
  while (T--) {
    Spell *spell = Arawn.cast(in);
    counterspell(spell);
  }
  return 0;
}