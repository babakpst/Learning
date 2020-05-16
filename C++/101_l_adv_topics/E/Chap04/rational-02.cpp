// rational-02.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-11
#include <cstdio>
#include <string>
#include <utility>

void message(const char * s) {
    puts(s);
    fflush(stdout);
}

// this version has messages to show which constructor (ctor) is being called.
class Rational {
    int _n = 0;
    int _d = 1;
    
    // c_str buffer
    static const int _bufsize = 128;
    mutable char * _buf = nullptr;
    
public:
    Rational() { reset(); message("default ctor"); }
    Rational(const int & numerator) : _n(numerator), _d(1) { message("int ctor"); }
    Rational(const int & numerator, const int & denominator) : _n(numerator), _d(denominator) { message("int,int ctor"); }
    Rational(const Rational & other) : _n(other._n), _d(other._d) { message("copy ctor"); }
    Rational(Rational &&) noexcept;
    ~Rational();
    void reset();
    inline int numerator() const { return _n; }
    inline int denominator() const { return _d; }
    Rational & operator = (const Rational &);
    Rational operator + (const Rational &) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
    operator std::string () const;
    std::string string() const;
    const char * c_str() const;
};

Rational::Rational(Rational && rhs) noexcept {
    message("move ctor");
    _n = std::move(rhs._n);
    _d = std::move(rhs._d);
    rhs.reset();
}

Rational::~Rational() {
    message("dtor");
    reset();
}

void Rational::reset() {
    _n = 0; _d = 1;
    if(_buf) delete [] _buf;
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

int main() {
    Rational a = 7;     // 7/1
    Rational b(5, 3);   // 5/3
    Rational c = b;     // copy ctor
    Rational d = std::move(c);
    
    printf("a is: %s\n", a.c_str());
    printf("b is: %s\n", b.c_str());
    printf("c is: %s\n", c.c_str());
    printf("d is: %s\n", d.c_str());
    
    printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    
    return 0;
}
