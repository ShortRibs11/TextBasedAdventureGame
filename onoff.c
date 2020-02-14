#include <stdio.h>
#include "object.h"
#include "match.h"
#include "reachable.h"
#include "toggle.h"

int executeTurnOn(void) {
  OBJECT *obj = reachableObject("what you want to turn on", params[0]);
  if (obj->turnOn == NULL) {
    printf("%s", cannotTurnOn());
  } else {
    printf("%s", (obj->turnOn)());
  }
  return 1;
}

int executeTurnOff(void) {
  OBJECT *obj = reachableObject("what you want to turn off", params[0]);
  if (obj->turnOff == NULL) {
    printf("%s", cannotTurnOff());
  } else {
    printf("%s", (obj->turnOff)());
  }
  return 1;
}
