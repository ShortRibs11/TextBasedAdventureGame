#include <stdio.h>
#include "object.h"
#include "move.h"
#include "string_util.h"
#include "misc.h"
#include "thief.h"

static int stole = 0;

const char *thiefUpdate() {
	OBJECT *tLoc = thief->location;
  char * reply = "A sneaky thief crawls through the passage heading ";

  if (tLoc == lampOn->location) {
    lampOn->location = thief;
  } else if (tLoc == player->location) {
    if (lampOn->location == player) {
      lampOn->location = thief;
			stole = 1;
      reply = "The thief swipes your lamp! He runs ";
    } else {
			OBJECT * obj;
			forEachObject(obj) {
				if (obj->location == player) {
		      obj->location = thief;
					stole = 1;
		      reply = combineStrings("The thief swipes ",
									combineStrings(obj->description, " from you! He runs ",
																	BUFFER_SIZE),BUFFER_SIZE);
					break;
				}
			}
		}
  }
	if (stole == 0) {
		OBJECT * obj;
		forEachObject(obj) {
			if (obj->location == tLoc) {
				// Try to steal the object
				printf("Checking %s...\n", obj->description);
//				const char * success = moveObject(obj, thief);
				// If the object was stolen successfully
//				if (obj->location == thief) {
				if ((obj->health == 0) &&
						(obj->weight < weightOfContents(thief) + thief->capacity)) {
					printf("Stealing %s.\n", obj->description);
					obj->location = thief;
					reply = combineStrings("The thief picks up a ",
									combineStrings(obj->description, " and scurries ",
																	BUFFER_SIZE),BUFFER_SIZE);
					stole = 1;
					break;
				}
			}
		}
	}

	stole = 0;

  if (tLoc == caveMaze1) {
    thief->location = caveMaze2;
		reply = combineStrings(reply, "east", BUFFER_SIZE);
  } else if (tLoc == caveMaze2) {
    thief->location = caveMaze3;
		reply = combineStrings(reply, "south", BUFFER_SIZE);
  } else if (tLoc == caveMaze3) {
    thief->location = caveMaze4;
		reply = combineStrings(reply, "west", BUFFER_SIZE);
  } else if (tLoc == caveMaze4) {
    thief->location = caveMaze1;
		reply = combineStrings(reply, "north", BUFFER_SIZE);
  }

  return combineStrings(reply, ".", BUFFER_SIZE);
}
