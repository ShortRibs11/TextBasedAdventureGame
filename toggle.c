#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "location.h"

void swapLocations(OBJECT *obj1, OBJECT *obj2) {
  OBJECT *tmp = obj1->location;
  obj1->location = obj2->location;
  obj2->location = tmp;
}

const char *cannotBeOpened(void)    { return "That cannot be opened.\n";    }
const char *cannotBeClosed(void)    { return "That cannot be closed.\n";    }
const char *cannotBeLocked(void)    { return "That cannot be locked.\n";    }
const char *cannotBeUnlocked(void)  { return "That cannot be unlocked.\n";  }

const char *isAlreadyOpen(void)    { return "That is already open.\n";     }
const char *isAlreadyClosed(void)  { return "That is already closed.\n";    }
const char *isAlreadyLocked(void)  { return "That is already locked.\n";    }
const char *isAlreadyUnlocked(void){ return "That is already unlocked.\n";    }

const char *isStillOpen(void)      { return "That is still open.\n";    }
const char *isStillLocked(void)    { return "That is still closed.\n";    }

const char *cannotTurnOn(void)     { return "It doesn't look like this can turn on.\n"; }
const char *cannotTurnOff(void)    { return "It doesn't look like this can turn off.\n"; }
const char *isAlreadyOff(void)     { return "This is already off.\n"; }
const char *isAlreadyOn(void)      { return "This is already on.\n"; }

const char *cannotLight(void)           { return "You try, but it fails to light.\n"; }
const char *cannotExtinguish(void)      { return "That cannot be put out.\n"; }
const char *isAlreadyLit(void)          { return "That is already lit.\n"; }
const char *isAlreadyExtinguished(void) { return "That is already out.\n"; }

void toggleReplace(OBJECT *old, OBJECT *new) {
  int oldLit = isLit(player->location);
  swapLocations(old, new);
  if (oldLit != isLit(player->location)) {
    triggerLookAround();
  }
}
