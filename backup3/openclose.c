#include <stdio.h>
#include "object.h"
#include "match.h"
#include "reachable.h"

int executeOpen(void) {
  OBJECT *obj = reachableObject("what you want to open", params[0]);
  if (obj != NULL) printf("%s", (*obj->open)());
  return 1;
}

int executeClose(void) {
  OBJECT *obj = reachableObject("what you want to close", params[0]);
  if (obj != NULL) printf("%s", (*obj->close)());
  return 1;
}

int executeLock(void) {
  OBJECT *obj = reachableObject("What you want to lock", params[0]);
  if (obj != NULL) printf("%s", (*obj->lock)());
  return 1;
}

int executeUnlock(void) {
  OBJECT *obj = reachableObject("What you want to unlock", params[0]);
  if (obj != NULL) printf("%s", (*obj->unlock)());
  return 1;
}
