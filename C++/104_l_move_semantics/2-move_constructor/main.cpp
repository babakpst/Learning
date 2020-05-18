// the code is adapted from rational.cpp by Bill Weinman <http://bw.org/>
// updated 2015-06-01

/*
notes:
To use move semantic in a class, we need to define a move constructor. 

*/

#include <cstdio>
#include <string>
#include <memory>


// MSC standards compliance issues
#define _NOEXCEPT noexcept

void message(const char * s) {
    puts(s); fflush(stdout);
}

// this version has messages to show which constructor (ctor) is being called.
class Rational {
    int _n = 0;
    int _d = 1;

    // c_str buffer
    static const int _bufsize = 128;
    mutable char * _buf = nullptr;

public:
    // constructors
    Rational() { reset(); message("default ctor"); }
    Rational(const int & numerator) : _n(numerator), _d(1) { message("int ctor"); }
    Rational(const int & numerator, const int & denominator) : _n(numerator), _d(denominator) { message("int,int ctor"); }
    Rational(const Rational & other) : _n(other._n), _d(other._d) { message("copy ctor"); }

    // new copy-move ctor. && this is an rvalue.
    Rational(Rational &&) _NOEXCEPT;

    ~Rational();

    void reset();
    inline int numerator() const { return _n; }
    inline int denominator() const { return _d; }

    // operator overload
    Rational & operator = (const Rational &);
    Rational operator + (const Rational &) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
    operator std::string () const;

    std::string string() const;
    const char * c_str() const;
};

Rational::~Rational() {
    message("dtor");
    reset();
}

Rational::Rational(Rational && rhs) _NOEXCEPT {
_n =std::move(rhs._n);
_d =std::move(rhs._d);
rhs.reset();
message("move ctor");
};

void Rational::reset() {
    _n = 0; _d = 1;
    delete [] _buf;
    _buf = nullptr;
}

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::operator std::string () const {
    return string();
}

std::string Rational::string () const {
    return std::string(c_str());
}

const char * Rational::c_str() const {
    if(!_buf) _buf = new char[_bufsize]();
    snprintf(_buf, _bufsize, "%d/%d", _n, _d);
    return _buf;
}


Rational f(Rational o){
return o;  // this calls the move costructor. 
}

int main( int argc, char ** argv ) {
    
    Rational a = 7;     // 7/1
    Rational b(5, 3);   // 5/3
    Rational c = b;     // copy ctor
    Rational d;         // default ctor
    
    printf("a is: %s\n", a.c_str());
    printf("b is: %s\n", b.c_str());
    printf("c is: %s\n", c.c_str());
    printf("d is: %s\n", d.c_str());

    Rational e=std::move(c);         // move ctor
    printf("c is: %s\n", c.c_str());
    printf("e is: %s\n", e.c_str());

    Rational g = f(e);
    printf("b is: %s\n", c.c_str());
    printf("g is: %s\n", g.c_str());
    
    printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    
    return 0;
}
