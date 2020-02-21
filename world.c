#include <stdio.h>
#include "object.h"
#include "world.h"

static int needWorldUpdate = 0;

void worldUpdate(void) {
  OBJECT *obj;
  forEachObject(obj) {
    if (obj->update != NULL) {
      OBJECT *oldLocation = obj->location;
      const char *string = (*obj->update)();
      if ((obj->location == player->location) || (oldLocation == player->location)) {
        printf("%s\n", string);
      }
    }
  }
}

int isWorldUpdateNeeded(void) {
	int answer = needWorldUpdate;
	needWorldUpdate = 0;
	return answer;
}

void triggerWorldUpdate(void) {
	needWorldUpdate = 1;
}

int executeWait(void) {
  triggerWorldUpdate();
  printf("You wait...\n");
  return 1;
}
