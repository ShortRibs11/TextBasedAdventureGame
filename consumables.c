#include <stdio.h>
#include "match.h"
#include "object.h"
#include "reachable.h"
#include "consumables.h"


const char *cannotEat(void)           { return "You can't eat that.\n"; }
const char *cannotDrink(void)           { return "You can't drink that.\n"; }


int executeEat(void) {
  OBJECT *obj = reachableObject("what you want to eat", params[0]);
  if (obj != NULL) {
    if (obj->customEat == NULL) {
      printf("%s", cannotEat());
    } else {
      printf("%s", (obj->customEat)());
    }
  }
  return 1;
}

int executeDrink(void) {
  OBJECT *obj = reachableObject("what you want to drink", params[0]);
  if (obj != NULL) {
    if (obj->customDrink == NULL) {
      printf("%s", cannotDrink());
    } else {
      printf("%s", (obj->customDrink)());
    }
  }
  return 1;
}
