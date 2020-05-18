// rational.cpp by Bill Weinman <http://bw.org/>
// updated 2015-06-01

//note: it is all about create efficient ctor, and copies in our classes.


#include <cstdio>
#include <string>
#include <memory>

#define _NOEXCEPT noexcept

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
    Rational(Rational &&) _NOEXCEPT;
    ~Rational();
    void reset();

    void swap( Rational & other);

    inline int numerator() const { return _n; }
    inline int denominator() const { return _d; }
    Rational & operator = ( Rational other );
    Rational & operator = (Rational &&) _NOEXCEPT;
    Rational operator + (const Rational &) const;
    Rational operator - (const Rational &) const;
    Rational operator * (const Rational &) const;
    Rational operator / (const Rational &) const;
    operator std::string () const;
    std::string string() const;
    const char * c_str() const;
};

Rational::Rational(Rational && other) _NOEXCEPT {
    _n = std::move(other._n);
    _d = std::move(other._d);
    other.reset();
    message("move ctor");
}

Rational::~Rational() {
    message("dtor");
    reset();
}

void Rational::reset() {
    _n = 0; _d = 1;
    delete [] _buf;
    _buf = nullptr;
}

void Rational::swap( Rational & other){
std::swap(_d,other._d);
std::swap(_n,other._n);
}


Rational & Rational::operator = ( Rational other ) {
    message("copy and swap");
    swap(other);
    return *this;
}

Rational & Rational::operator = ( Rational && rhs ) _NOEXCEPT {
    message("move assignment");
    if( this != &rhs ) {
        _n = std::move(rhs.numerator());
        _d = std::move(rhs.denominator());
        rhs.reset();
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

int main( int argc, char ** argv ) {
    
    Rational a = 7;     // 7/1
    Rational b(5, 3);   // 5/3
    Rational c = b;     // copy ctor
    Rational d = std::move(c);
    
    //d = std::move(b);
    d = b;
    
    printf("a is: %s\n", a.c_str());
    printf("b is: %s\n", b.c_str());
    printf("c is: %s\n", c.c_str());
    printf("d is: %s\n", d.c_str());
    
    printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    

    Rational aa(5,3);
    Rational bb(9,5);
    //bb = std::move(aa); // ambiguous, bcs both swap and move assingment operator.
    bb=aa;

    printf("aa: %s \n", aa.c_str());
    printf("bb: %s \n", bb.c_str());

    return 0;
}
