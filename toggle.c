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

const char *toggleBackdoor(void)   {
  swapLocations(openDoorToBackroom, closedDoorToBackroom);
  swapLocations(openDoorToCave, closedDoorToCave);
  return "OK.\n";
}

const char *toggleBox(void)        {
  swapLocations(openBox, closedBox);
  return "OK.\n";
}

const char *toggleBoxLock(void)    {
  if (keyForBox->location == player) {
    swapLocations(closedBox, lockedBox);
    return "OK.\n";
  } else {
  return "You don't have a key.\n";
  }
}

void toggleLamp(void) {
/*  int oldLit = isLit(player->location);
  swapLocations(lampOn, lampOff);
  printf("OK.\n");
  if (oldLit != isLit(player->location)) {
    printf("\n");
    executeLookAround();
  }*/
}

void toggleReplace(OBJECT *old, OBJECT *new) {
  int oldLit = isLit(player->location);
  swapLocations(old, new);
//  printf("OK.\n");
  if (oldLit != isLit(player->location)) {
//    printf("\n");
//    executeLookAround();
    triggerLookAround();
  }
}

/*
const char *toggleOn(OBJECT *obj) {
  swapLocations(obj, obj->turnOn);
  printf("OK.\n");
}

const char *toggleOff(OBJECT *obj) {
  swapLocations(obj, obj->turnOff);
  printf("OK.\n");
}
*/
