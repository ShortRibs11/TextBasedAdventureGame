#include <stdio.h>
#include "match.h"
#include "object.h"
#include "reachable.h"
#include "combat.h"


const char *cannotFight(void)           { return "Your attempts to pick a fight with that fail.\n"; }


int executeFight(void) {
  OBJECT *obj = reachableObject("what you want to fight", params[0]);
  if (obj != NULL) {
    if (obj->customFight == NULL) {
      printf("%s", cannotFight());
    } else {
      printf("%s", (obj->customFight)());
    }
  }
  return 1;
}
