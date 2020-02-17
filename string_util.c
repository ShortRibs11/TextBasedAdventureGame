#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_util.h"
/*
void main(void) {
  char firstString[19] = "There is a first, ";
  char secondString[14] = "and a second.";
  char *str = secondString;
  printf("%d and %d", (int)strlen(firstString), (int)strlen(secondString));
  printf("%s\n", combineStrings(firstString, str, 255));
}
*/
char *combineStrings(const char *str1, const char *str2, int size) {

  int i, j;
  char* string = malloc(sizeof(string)*(strlen(str1) + strlen(str2)));
//  printf("First string = %s\n", str1);
  for (i=0, j=0; i < size && j < (int)strlen(str1); i++, j++) {
    string[i] = str1[j];
    string[i+1] = '\0';
//    printf("Adding %c to string for \"%s\".\n", str1[j], string);
  }
//  printf("Second string = %s\n", str2);
  for (j=0; i < size && j < (int)strlen(str2); i++, j++) {
    string[i] = str2[j];
    string[i+1] = '\0';
//    printf("Adding %c to string for \"%s\".\n", str2[j], string);
  }
  string[i] = '\0';
  return string;
}
