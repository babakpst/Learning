/*

Babak Poursartip
01/05/2021

SFINAE

*/

#include <iostream>

// 1 ===============

template<typename Ty, Ty V>
struct integral_constant
{
  static constexpr Ty value = V;
};

template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

// 2 ===============
template <class T> struct is_reference: false_type{};
template <class T> struct is_reference<T&>: true_type{};
template <class T> struct is_reference<T&&>: true_type{};

template <class T>
inline constexpr bool is_reference_v = is_reference<T>::value;

// 3 ===============
template <class T> struct remove_reference { using type = T; };
template <class T> struct remove_reference<T&> { using type = T; };
template <class T> struct remove_reference<T&&> { using type = T; };

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

// 4 ===============
template<class T> struct add_lvalue_reference{using type = T&;};
template<> struct add_lvalue_reference<void>{using type = void;};

template<class T> 
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

// 5 ===============
template<class T, class Enable>
struct ALR_impl { using type = T; };

template<class T> // partial specialization
struct ALR_impl<T, remove_reference <T&>> { using type = T&;};

template<class T>
struct add_lvalue_reference2: ALR_impl<T, remove_reference<T>> {}; // this is using the partial specialization. 

//===============
//===============
int main()
{
  std::cout << " starts ... \n";

  // ==============
  std::cout <<std::boolalpha << true_type::value << std::endl;
  std::cout <<std::boolalpha << false_type::value << std::endl;

  // ==============
  static_assert( is_reference_v<int&>);
  static_assert( is_reference_v<int&&>);
  //static_assert( is_reference_v<int>); // static assertation fails here, no specialization for this.

  std::cout <<std::boolalpha << std::is_same_v<remove_reference_t<int&>,int> << std::endl;
    
  // ==============
  static_assert( std::is_same_v<remove_reference_t<int&>,int>);
  static_assert( std::is_same_v<remove_reference_t<int>,int>);

  // ==============
  static_assert(std::is_same_v<add_lvalue_reference_t<int&&>, int&>);
  static_assert(std::is_same_v<add_lvalue_reference_t<int&>, int&>);
  static_assert(std::is_same_v<add_lvalue_reference_t<int>, int&>);
  static_assert(std::is_same_v<add_lvalue_reference_t<void>, void>); // error w/o specialization

  // 5 ==============
  std::cout << " 5: type is: " << typeid(
  typename add_lvalue_reference2<int>::type   /* output is int&, using the partial specialization */
  ).name() << std::endl;

  std::cout << " 5: type is: " << typeid(int&).name() << std::endl;
  std::cout << " 5 output is int&: " << std::boolalpha << 
        std::is_same_v< typename add_lvalue_reference2<int>::type, int&> << std::endl;
  
  std::cout << " 5 output is int: " << std::boolalpha << 
        std::is_same_v< typename add_lvalue_reference2<int>::type, int> << std::endl;

  std::cout << " 5 output is void: " << std::boolalpha << // uses the base template bcs void& does not exist.
        std::is_same_v< typename add_lvalue_reference2<void>::type, void> << std::endl;


  // ==============
  std::cout << " done \n";
  return 0;
}
