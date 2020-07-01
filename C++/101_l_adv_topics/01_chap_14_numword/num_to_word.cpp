
#include "num_to_word.h"

// =================================================
num_to_word::num_to_word(){puts(" number to word.");}

// =================================================
unsigned num_to_word::GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

// =================================================
const char* num_to_word::One_digit(int n){
switch (n){
  case 1: return "one"; break;
  case 2: return "two"; break;
  case 3: return "three"; break;
  case 4: return "four"; break;
  case 5: return "five"; break;
  case 6: return "six"; break;
  case 7: return "seven"; break;
  case 8: return "eight"; break;
  case 9: return "nine"; break;
  case 10: return "ten"; break;
  case 11: return "eleven"; break;
  case 12: return "twelve"; break;
  case 13: return "thirteen"; break;
  case 14: return "fourteen"; break;
  case 15: return "fifteen"; break;
  case 16: return "sixteen"; break;
  case 17: return "seventeen"; break;
  case 18: return "eighteen"; break;
  case 19: return "nineteen"; break;
  case 20: return "twenty"; break;
};
  return "";
}

const char* num_to_word::two_digit(int n){
switch (n){
  case 2: return "twenty"; break;
  case 3: return "thrity"; break;
  case 4: return "forty"; break;
  case 5: return "fifty"; break;
  case 6: return "sixty"; break;
  case 7: return "seventy"; break;
  case 8: return "eighty"; break;
  case 9: return "ninety"; break;
};
  return "";
}


const char* num_to_word::p_digit(int n){
switch (n){
  case 1: return "hundred"; break;
  case 2: return "thousand"; break;
  case 3: return "million"; break;
  case 4: return "billion"; break;
  case 5: return "trillion"; break;
  case 6: return "megamillion"; break;
  case 7: return ""; break;
  case 8: return ""; break;
  case 9: return ""; break;
};
  return "";
}




// =================================================
void num_to_word::words(uint64_t n){
printf("%" PRIu64 "\n",n);

nDigits = GetNumberOfDigits(n);
if ((nDigits %3) == 0) nGroups = nDigits/3;
else nGroups = nDigits/3+1;

printf(" \n digits/groups: %u %u \n\n",nDigits, nGroups);

uint64_t power;
uint64_t rem,digit;
uint64_t num = n;

  for (unsigned i = nGroups; i>0; --i){
    power = pow(10,(i-1)*3);
    rem = num % power;
    digit = (num - rem)/power;
    num = rem;

    //printf(" 3 no %u \n", (int)digit);

    rem  = digit % 100;
    digit= (digit - rem)/100;
    if (digit != 0) printf("%s %s ", One_digit( (int)digit), p_digit( 1 )  );
    digit = rem;
    if (digit <= 20) printf("%s ", One_digit( (int)digit));
    else{
      rem  = digit % 10;
      digit= (digit - rem)/10;
      printf("%s %s ", two_digit( (int)digit), One_digit( (int)rem));
    }

    /*
      power = pow(10,(i-1));
      rem = num % power;
      digit = (num - rem)/power;
      num = rem;
      printf("%d %d %d %d %d \n",i, (int)power, (int)rem, (int)num, (int)digit );
      printf("%s %s \n",One_digit( (int)digit ), p_digit( i ));
    */
    if (i>1) printf("%s ", p_digit( i ));
  }
  printf("\n ");


}









































