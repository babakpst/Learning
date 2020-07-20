#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

//==========================
static int loop (
    const int max)
{
    int i = 0;
    while (i < max)
        ++i;    
    return i;
}

//==========================
static int recurse (
    const int max,
    int* call_num)
{
    ++(*call_num);
    if (*call_num < max)
        recurse (max, call_num);
    return *call_num;
}

//==========================
static int find_random (
    const int     max_attempts,
    const uint8_t num_to_find)
{
    const uint8_t max = 255;
    srand (time(NULL));
    
    int hits = 0;
    int i = max_attempts;
    while (i--)
    {
        int rand_num = rand() % max;
        if (rand_num == num_to_find)
            ++hits;
    }
    
    return hits;
}

//==========================
int main(int argc, char *argv[])
{
    const int max = 100000;
    int call_num = 0;
    
    printf ("Looped %d times\n", loop (max));
    printf ("Recursed %d times\n", recurse (max, &call_num));
    
    uint8_t num_to_find = 55;
    int hits = find_random (max, num_to_find);
    printf ("Found number '%d' %d times over %d attempts\n",
            num_to_find, hits, max);

    return 0;
}
