// new-delete.cpp by Bill Weinman <http://bw.org/>
// Bill Weinman

// new/del allows allocate and deallocate memory




#include <cstdio>
#include <new>

class c1 {
    int _a = 0;
    int _b = 0;
    int _c = 0;
public:
    c1(int i = 0);
    ~c1();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
};

c1::c1(int i) : _a(i), _b(i + 1), _c(i + 2) {
    puts("c1 constructor");
}

c1::~c1() {
    puts("c1 destructor");
}

int main() {
    // generating the objects with try exceptions block
    try {
        c1 * o1 = new c1; // create a pointer object from c1
        printf("o1: %d, %d, %d\n", o1->a(), o1->b(), o1->c());
        delete o1;
        
        // creating an array of objects: for each element the constructor will be called.
        c1 *o2 = new c1[5]; 
        delete[] o2;  // corresponding array version of the delete operator
    } catch (std::bad_alloc & ba) {
        printf("new c1 failed: %s\n", ba.what());
        return 1;
    }
    
    // generating the object without the try/catch:
    // create a pointer object from c1, do not throw an exception, but to test
    // test whether this object is successful, we will return a null pointer if it 
    // is not successful;
    puts("");
    c1 * o3 = new(std::nothrow) c1; 
    if (o3 == nullptr) {
      puts(" new c1 failed. ");
      return 1; // return 1 is an error return code for main.
    }
    printf("o3: %d, %d, %d\n", o3->a(), o3->b(), o3->c());
    delete o3;

   
    return 0;
}
