
/*
07082021

Function pointer

1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.
2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.
3) A function’s name can also be used to get functions’ address. For example, in the below program, we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works
4) Like normal pointers, we can have an array of function pointers. Below example in point 5 shows syntax for array of pointers.
5) Function pointer can be used in place of switch case. For example, in below program, user is asked for a choice between 0 and 2 to do different tasks.
6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.

*/
#include <iostream>

  
// Two simple functions
void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }
  
// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)())
{
    fun();
}

void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}

int func(int a)
{
std::cout << " inside func " << a <<"\n";
return 2*a;
}


int main()
{

std::cout << " starts \n";

// function pointer 
// 1 =======================
int (*myFunctor)(int); // myFunctor has one argument of type int
myFunctor = &func;

int b1 = (*myFunctor)(10);
std::cout << " here: " << b1 << std::endl;


// 2 =======================
// remark 3
int (*myFuncPointer)(int) = func;
int b2 = myFuncPointer(11);
std::cout << " here: " << b2 << std::endl;


// 3 =======================
// remark 4+5
void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
unsigned int ch, a = 15, b = 10;
  
//printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply\n");
//scanf("%d", &ch);
ch = 1;

if (ch > 2) return 0;

(*fun_ptr_arr[ch])(a, b);

// 4 =======================
// remark 6
wrapper(fun1);
wrapper(fun2);

std::cout << " end \n";
return 10;
}
