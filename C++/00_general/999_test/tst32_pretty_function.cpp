
#include <iostream>

namespace N {
    class C {
        public:
            template <class T>
            static void f(int i) {
                (void)i;
                std::cout << "__func__            " << __func__ << std::endl
                          << "__FUNCTION__        " << __FUNCTION__ << std::endl
                          << "__PRETTY_FUNCTION__ " << __PRETTY_FUNCTION__ << std::endl;
            }
            template <class T>
            static void f(double f) {
                (void)f;
                std::cout << "__PRETTY_FUNCTION__ " << __PRETTY_FUNCTION__ << std::endl;
            }
    };
}


int main() {
    N::C::f<char>(1);
    N::C::f<void>(1.0);
}
