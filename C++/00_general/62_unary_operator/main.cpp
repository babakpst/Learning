/*
Babak Poursartip
09/30/2020


unary operator:
operators that act upon a single operand to produce a new value. The unary
operators are as follows:


Operators                            | Description
--------------------------------------------------------------------------------
Indirection operator (*)             |  It operates on a pointer variable and
                                     |  returns an l-value equivalent to the
                                     |  value at the pointer address. This is
                                     |  called "dereferencing" the pointer
--------------------------------------------------------------------------------
Address-of operator (&)              | The unary address-of operator (&) takes
                                     | the address of its operand. The operand
                                     | of the address-of operator can be either
                                     | a function designator or an l-value that
                                     | designates an object that is not a bit
                                     | field and is not declared with the
                                     | register storage-class specifier.
--------------------------------------------------------------------------------
Unary plus operator (+)              | The result of the unary plus operator (+)
                                     | is the value of its operand. The operand
                                     | to the unary plus operator must be of an
                                     | arithmetic type.
--------------------------------------------------------------------------------
Unary negation operator (-)          | The - (unary minus) operator negates the
                                     | value of the operand. The operand can
                                     | have any arithmetic type. The result is
                                     | not an lvalue.
--------------------------------------------------------------------------------
Logical negation operator (!)        | The logical negation operator (!)
                                     | reverses the meaning of its operand. The
                                     | operand must be of arithmetic or pointer
                                     | type (or an expression that evaluates to
                                     | arithmetic or pointer type). The operand
                                     | is implicitly converted to type bool.
--------------------------------------------------------------------------------
One's complement operator (~)        | The one's complement operator sometimes
                                     | called the "bitwise complement" or
                                     | "bitwise NOT" operator, produces the
                                     | bitwise one's complement of its operand.
                                     | The operand must be of integral type.
--------------------------------------------------------------------------------
Prefix increment operator (++)       | The prefix increment operator ( ++ ) adds
                                     | one to its operand; this incremented
                                     | value is the result of the expression.
                                     | The operand must be an l-value not of
                                     | type const. The result is an l-value of
                                     | the same type as the operand.
--------------------------------------------------------------------------------
Prefix decrement operator (--)       | The prefix decrement operator ( -- )
                                     | subtracts one from its operand; this
                                     | decremented value is the result of the
                                     | expression. The operand must be an
                                     | l-value not of type const. The result is
                                     | an l-value of the same type as the
                                     | operand.
--------------------------------------------------------------------------------
Cast operator ()                     | A type cast provides a method for
                                     | explicit conversion of the type of an
                                     | object in a specific situation. The
                                     | compiler treats cast-expression as type
                                     | type-name after a typecast has been made.
--------------------------------------------------------------------------------
sizeof operator                      | It is a compile-time unary operator which
                                     | can be used to compute the size of its
                                     | operand.
--------------------------------------------------------------------------------
new operator                         | It is a memory allocation operator that
                                     | is used to allocate memory dynamically.
--------------------------------------------------------------------------------
delete operator                      | It is a memory allocation operator that
                                     | is used to deallocate memory that was
                                     | dynamically allocated.
--------------------------------------------------------------------------------

*/

#include <iostream>

using namespace std;

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  int x;
  float y = 1.23;
  x = (int)y;
  x = -x;
  cout << x;

  cout << " \n ends\n";

  return 0;
}