/*

Babak Poursartip
01/05/2021

SFINAE

*/

#include <iostream>

//===============

template<typename Ty, Ty V>
struct integral_constant
{
  static constexpr Ty value = V;
};


template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

//===============
template <class T> struct is_reference: false_type{};
template <class T> struct is_reference<T&>: true_type{};
template <class T> struct is_reference<T&&>: true_type{};

template <class T>
inline constexpr bool is_reference_v = is_reference<T>::value;

//===============
template <class T> struct remove_reference { using type = T; };
template <class T> struct remove_reference<T&> { using type = T; };
template <class T> struct remove_reference<T&&> { using type = T; };

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

//===============
int main()
{
  std::cout << " starts ... \n";

  std::cout <<std::boolalpha << true_type::value << std::endl;
  std::cout <<std::boolalpha << false_type::value << std::endl;

  static_assert( is_reference_v<int&>);
  static_assert( is_reference_v<int&&>);
  //static_assert( is_reference_v<int>); // static assertation fails here, no specialization for this.

  std::cout <<std::boolalpha << std::is_same_v<remove_reference_t<int&>,int> << std::endl;
    
  static_assert( std::is_same_v<remove_reference_t<int&>,int>);
  static_assert( std::is_same_v<remove_reference_t<int>,int>);

  std::cout << " done \n";
  return 0;
}
