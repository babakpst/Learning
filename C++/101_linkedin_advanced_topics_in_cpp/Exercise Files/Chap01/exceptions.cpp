// exceptions.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-04
#include <cstdio>
#include <string>
#include <exception>
using namespace std;

static string unk = "unknown";
static string clone_prefix = "clone-";

class E : public exception {
    const char * msg = nullptr;
    E(){};
public:
    E(const char * s) throw() : msg(s) {}
    const char * what() const throw() { return msg; }
};

class Animal {
    string _type = "";
    string _name = "";
    string _sound = "";
public:
    Animal();   // default constructor
    Animal(const string & type, const string & name, const string & sound);
    Animal(const Animal &); // copy constructor
    Animal & operator = (const Animal &); // copy operator
    ~Animal();  // destructor
    
    void print() const;
};

// -- implementation --
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");
    if(type.empty() || name.empty() || sound.empty()) {
        throw E("Insufficient parameters");
    }
}

Animal::Animal(const Animal & rhs) {
    puts("copy constructor");
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print () const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator = (const Animal & rhs) {
    puts("copy operator");
    if(this != &rhs) {
        _name = clone_prefix + rhs._name;
        _type = rhs._type;
        _sound = rhs._sound;
    }
    return *this;
}

int main() {
    try {
        Animal x("bear", "yogi", "");
        x.print();
    } catch ( exception & e ) {
        printf("Animal x: %s\n", e.what());
    }
    
    return 0;
}
