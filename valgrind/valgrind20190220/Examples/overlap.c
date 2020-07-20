#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char string[] = "an example string";
  char* offset;

  // Drop the first word using an overlapping copy
  offset = strchr(string,' ');
  if (offset)
    strcpy(string, offset+1);

  // Print results
  printf("truncated string is: %s\n", string);

  return 0;
}
