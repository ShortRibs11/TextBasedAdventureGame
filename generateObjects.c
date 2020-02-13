#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 255
#define MAX_OBJECTS 255
#define MAX_PROPS 25

char *propNames;

typedef struct gameObject {
  char name[BUFFER_SIZE];
  char propNames[MAX_PROPS][BUFFER_SIZE];
  char props[MAX_PROPS][BUFFER_SIZE];
  int propCount;
} OBJECT;

OBJECT objectList[MAX_OBJECTS];

char getNextWord(FILE *file, char output[BUFFER_SIZE], int length) {
  int idx;
  {
    char stopper;
    // Find the beginning of the non-whitespace
    for (idx=0; idx < length; idx++) {
      // If the current character is not whitespace
      if (  ((stopper = fgetc(file)) != ' ') &&
            ((stopper = fgetc(file)) != '\t') &&
            ((stopper = fgetc(file)) != '\n')) {
        output[0] = stopper;
      }
    }

  }
}

char putWordIntoString()

void main(void) {
  FILE *objectText = fopen("object.txt", "r");
  FILE *objectHeader = fopen("object.h", "w+");
//  FILE *objectSource = fopen("object.c", "w+");

  int read;
  for (read = fgetc(objectText);
      ((read != EOF) && (read != '-'));
      read = fgetc(objectText)) {
    fputc(read, objectHeader);
  }
/*  do {
    fputc(read, objectHeader);
    printf("Writing %c to file.\n", read);
  }
  while (((read = fgetc(objectText)) != EOF) && (read != '-'));
  */

  char *line;
  char *stop;
  char buff[BUFFER_SIZE];
  int count;
  // Loop through every object, denoted by '-' symbols
  for (count = 0, line = fgets(buff, BUFFER_SIZE, objectText);
      count < MAX_OBJECTS && read != EOF;
      count++) {

  }

  fclose(objectText);
  fclose(objectHeader);
}
