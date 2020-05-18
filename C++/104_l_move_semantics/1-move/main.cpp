// main.cpp by Bill Weinman <http://bw.org/>

#include <cstdio>
#include <vector>
#include <string>
#include <utility>

void printMessage(const std::string & s) {
    puts(s.c_str()); fflush(stdout);
}

void print_vec(const std::vector<std::string> & v) {
    size_t size = v.size();
    printf("size of the vector: %ld\n", size);
    if(size) {
        for( std::string s : v ) { // this is great. 
            printf("[%s]", s.c_str());
        }
        puts("");
    }
    fflush(stdout);
}

// we can use move to define a swap function.
template<typename T>
void swap_vectors(T &a, T &b){
// no copying involved, just moving.
printMessage("swapping vectors");
T temp(std::move(a));
a = std::move(b);
b = std::move(temp);
}


int main( ) {
    std::vector<std::string> vec1 = { "val1", "val2", "val3", "val4", "val5" };
    std::vector<std::string> vec2 = { "val6", "val7", "val8", "val9", "val10" };
    
    printMessage("vector 1");
    print_vec(vec1);
    printMessage("vector 2");
    print_vec(vec2);

    // vec1 and vec2 are identical now.
    vec2 = vec1;
    printf("\n");
    printMessage("vector 1 2");
    print_vec(vec1);
    printMessage("vector 2 2");
    print_vec(vec2);

    // vec1 is rvalue. after this, vec1 is empty. and vec2 is vec1. no copying.
    vec2 = std::move(vec1);
    printf("\n");
    printMessage("vector 1 3");
    print_vec(vec1);
    printMessage("vector 2 3");
    print_vec(vec2);

    vec1 = { "val1", "val2", "val3", "val4", "val5" };
    vec2 = { "val6", "val7", "val8", "val9", "val10" };

    // swapping vectors
    swap_vectors<std::vector<std::string>>(vec1, vec2);
    //::swap_vectors(vec1, vec2);
    //std::swap_vectors(vec1, vec2);  // standard swap 
    printf("\n");
    printMessage("vector 1 4");
    print_vec(vec1);
    printMessage("vector 2 4");
    print_vec(vec2);


    return 0;
}
