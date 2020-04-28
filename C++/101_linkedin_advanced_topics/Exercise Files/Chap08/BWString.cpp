//  BWString.cpp
//  A simple smart string class
//  (c) 1995-2018 Bill Weinman <http://bw.org/>
//  version as of 2018-10-12

#include "BWString.h"

// MARK: - constructors/destructors

BWString::BWString( ) {
    reset();
}

BWString::BWString( const char * s ) {
    copy_str(s);
}

BWString::BWString( const BWString & old ) {
    copy_str(old);
}


BWString::~BWString() {
    reset();
}

// move constructor
BWString::BWString( BWString && other ) noexcept {
    reset();
    _str = other._str;
    _str_len = other._str_len;
    other._str = nullptr;
    other._str_len = 0;
    other.reset();
}

// MARK: - private methods

void BWString::_reset_split_array() const {
    if (_split_count) {
        // dtor the elements in the array
        while(_split_count) {
            _split_array[--_split_count].reset();
        }
        _split_array.reset();
        _split_count = 0;
    }
}

void BWString::_append_split_array(const BWString & s) const {
    if (_split_count >= _bwstring_max_split) return;
    if (!_split_count) {
        _split_array.reset(new _bwsp[_bwstring_max_split + 1]);
    }
    _split_array[_split_count] = std::make_shared<BWString>(s);
    ++ _split_count;
}

// MARK: - public methods

const char * BWString::alloc_str( size_t sz ) {
    if (_str) reset();
    _str_len = (sz > _bwstring_max_len) ? _bwstring_max_len : sz;
    _str = new char[_str_len + 1]();  // new char[]() fills with 0
    return _str;
}

void BWString::reset() {
    _reset_split_array();
    if(_str) {
        delete [] _str;
        _str = nullptr;
        _str_len = 0;
    }
}

void BWString::swap(BWString & other) {
    std::swap(_str, other._str);
    std::swap(_str_len, other._str_len);
}

const char * BWString::c_str() const {
    return _str;
}

const char * BWString::copy_str( const char * s) {
    if(s) {
        size_t len = strnlen(s, _bwstring_max_len);
        alloc_str(len);
        strncpy((char *)_str, s, len);
        _str_len = len;
    }
    return _str;
}

// MARK: - operators

// copy-and-swap assignment
BWString & BWString::operator = ( BWString other ) {
    swap(other);
    return *this;
}

BWString & BWString::operator += ( const char * rhs ) {
    if(rhs) {
        size_t newlen = _str_len + strnlen(rhs, _bwstring_max_len);
        if (newlen > _bwstring_max_len) newlen = _bwstring_max_len;
        
        size_t rhslen = newlen - _str_len;
        if(rhslen < 1) return *this;
        
        char * buf = new char[newlen + 1]();
        if(_str && _str_len) memcpy(buf, _str, _str_len);
        memcpy(buf + _str_len, rhs, rhslen);
        copy_str(buf);
        delete [] buf;
    }
    return *this;
}

BWString & BWString::operator += ( const BWString & rhs ) {
    operator+=(rhs.c_str());
    return *this;
}

const char BWString::operator[] ( const int index ) const {
    if(index < 0) return 0;
    if(index >= (int) _str_len) return 0;
    else return _str[index];
}

// MARK: - comparison operators

bool BWString::operator == ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) == 0 ) return true;
    else return false;
}

bool BWString::operator != ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) != 0 ) return true;
    else return false;
}

bool BWString::operator > ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) > 0 ) return true;
    else return false;
}

bool BWString::operator < ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) < 0 ) return true;
    else return false;
}

bool BWString::operator >= ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) >= 0 ) return true;
    else return false;
}

bool BWString::operator <= ( const BWString & rhs ) const {
    if( std::strncmp(this->c_str(), rhs.c_str(), _bwstring_max_len) <= 0 ) return true;
    else return false;
}

// MARK: - conversion operators

BWString::operator const char * () const {
    return c_str();
}

// MARK: - Utility methods

bool BWString::have_value() const {
    if(_str) return true;
    else return false;
}

// string format
BWString & BWString::format( const char * format , ... ) {
    char * buffer;
    
    va_list args;
    va_start(args, format);
    
    vasprintf(&buffer, format, args);
    copy_str(buffer);
    free(buffer);   // vasprintf uses malloc
    return *this;
}

// trim leading and trailing spaces
BWString & BWString::trim() {
    const static char * whitespace = "\x20\x1b\t\r\n\v\b\f\a";
    
    if(!have_value()) return *this; // make sure we have a string
    
    size_t begin = 0;
    size_t end = length() - 1;
    
    for (begin = 0; begin <= end; ++begin) {
        if (strchr(whitespace, _str[begin]) == nullptr) {
            break;
        }
    }
    
    for ( ; end > begin; --end) {
        if (strchr(whitespace, _str[end]) == nullptr) {
            break;
        } else {
            _str[end] = '\0';
        }
    }
    
    if (begin) {
        for (size_t i = 0; _str[i]; ++i) {
            _str[i] = _str[begin++];
        }
    }
    
    _str_len = strlen(_str);
    return *this;
}

BWString BWString::lower() const {
    BWString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i) {
        rs._str[i] = tolower(rs._str[i]);
    }
    return rs;
}

BWString BWString::upper() const {
    BWString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i) {
        rs._str[i] = toupper(rs._str[i]);
    }
    return rs;
}

const char & BWString::back() const {
    return _str[length() - 1];
}

const char & BWString::front() const {
    return _str[0];
}

// MARK: - find and replace methods

long int BWString::char_find( const char & match ) const {
    for (size_t i = 0; _str[i]; ++i) {
        if(_str[i] == match) return i;
    }
    return -1;
}

const BWString & BWString::char_repl( const char & match, const char & repl ) {
    for (size_t i = 0; _str[i]; ++i) {
        if(_str[i] == match) _str[i] = repl;
    }
    return *this;
}

BWString BWString::substr( size_t start, size_t length ) {
    BWString rs;
    char * buf;
    if ((length + 1) > _bwstring_max_len || (start + length) > _bwstring_max_len) return rs;
    if (length > _str_len - start) return rs;
    if (!_str) return rs;
    
    buf = new char[length + 1]();
    memcpy(buf, _str + start, length);
    rs = buf;
    delete [] buf;
    
    return rs;
}

long BWString::find( const BWString & match ) const {
    char * pos = strstr(_str, match.c_str());
    if(pos) return (long) ( pos - _str );
    else return -1;
}

const BWString BWString::replace( const BWString & match, const BWString & repl ) {
    BWString rs;
    long f1 = find(match);
    if (f1 >= 0) {
        size_t pos1 = (size_t) f1;
        size_t pos2 = pos1 + match.length();
        BWString s1 = pos1 > 0 ? substr(0, pos1) : "";
        BWString s2 = substr(pos2, length() - pos2);
        rs = s1 + repl + s2;
    }
    return rs;
}

// MARK: - split methods

// non-destructive split
const BWString::split_ptr & BWString::split( const char match ) const {
    const char match_s[2] = { match, 0 };
    return split(match_s, -1);
}

const BWString::split_ptr & BWString::split( const char * match ) const {
    return split(match, -1);
}

const BWString::split_ptr & BWString::split( const char * match, int max_split ) const {
    _reset_split_array();
    if (length() < 1) return _split_array;
    if (max_split < 0) max_split = _bwstring_max_split;
    
    size_t match_len = strnlen(match, _bwstring_max_len);
    if(match_len >= _bwstring_max_len) return _split_array;
    
    char * mi;              // match index
    char * pstr = _str;     // string pointer
    while (( mi = strstr(pstr, match)) && --max_split ) {
        if(mi != pstr) {
            size_t lhsz = mi - pstr;
            char * cslhs = new char[lhsz + 1]();
            memcpy(cslhs, pstr, lhsz);
            _append_split_array(cslhs);
            delete [] cslhs;
            pstr += lhsz;
        }
        pstr += match_len;
    }
    
    if (*pstr != '\0') {
        _append_split_array(pstr);
    }
    
    return _split_array;
}

// zero-based index of _split_array
const BWString & BWString::split_item( size_t index ) const {
    if(_split_count > index) return *_split_array[index];
    else return *this;
}

// MARK: - non-member operator overloads

BWString operator + ( const BWString & lhs, const BWString & rhs ) {
    BWString rs = lhs;
    rs += rhs;
    return rs;
}

#ifdef _MSC_VER

// MARK: - MS missing standard-ish functions

int vasprintf(char ** ret, const char * format, va_list ap)
{
    int len;
    char *buffer;
    
    len = _vscprintf(format, ap) + 1;
    buffer = (char *) malloc(len * sizeof(char));
    if (!buffer) return 0;
    vsprintf_s(buffer, len, format, ap);
    *ret = buffer;
    return len -1;
}

#endif // _MSC_VER
