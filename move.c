#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_util.h"
#include "object.h"
#include "world.h"
#include "misc.h"

const char* moveObject(OBJECT *obj, OBJECT *to) {
//	char reply[BUFFER_SIZE] = {0x0};
	char *reply = NULL;
//	char buffer[25] = {0x0};
	if (obj == NULL) {
		// Already handled by getVisible or getPossession
	} else if (to == NULL) {
//		strcpy(reply, "There is nobody here to give that to.\n");
		reply = "There is nobody here to give that to.\n";
	} else if (to->capacity == 0) {
/*		reply = (obj == keyForBox && (to == closedBox || to == lockedBox) ?
								"The key seems to fit the lock alright.\n" :
								"It doesn't seem to fit in.\n");
								*/
		reply = "It doesn't seem to fit in.\n";
	} else if (obj->weight == to->capacity) {
		reply = "That is way too heavy.\n";
	} else if (obj->weight + weightOfContents(to) > to->capacity) {
		reply = ("That would become too heavy.\n");
	} else {
		// Error handling done, movement will occur
		// Describe the movement to the player
		if (to == player->location) {
			reply = combineStrings("You drop ", combineStrings(obj->description, ".\n",
										BUFFER_SIZE), BUFFER_SIZE);
		} else if (to != player) {
			reply = (to->health > 0
										?		combineStrings("You give ",
												combineStrings(obj->description,
												combineStrings(" to ",
												combineStrings(to->description, ".\n",
													BUFFER_SIZE),BUFFER_SIZE),
													BUFFER_SIZE),BUFFER_SIZE)
										:		combineStrings("You put ",
												combineStrings(obj->description,
												combineStrings(" in ",
												combineStrings(to->description, ".\n",
													BUFFER_SIZE),BUFFER_SIZE),
													BUFFER_SIZE),BUFFER_SIZE)
						);
		} else if (obj->location == player->location) {
//			free(obj->integrated);
			obj->integrated = NULL;
			reply = combineStrings("You pick up ",combineStrings(obj->description, ".\n",
															BUFFER_SIZE),BUFFER_SIZE);
		} else {
//			free(obj->integrated);
			obj->integrated = NULL;
			reply = combineStrings("You get ", combineStrings(obj->description,
							combineStrings(" from ",
							combineStrings(obj->location->description, ".\n",
													BUFFER_SIZE),BUFFER_SIZE),BUFFER_SIZE),BUFFER_SIZE);
		}
		// Actuate the movement
		obj->location = to;
		// Update the world
		triggerWorldUpdate();
	}
	if (reply == NULL) {
		reply = "";
	}
	char *ret = reply;
	return ret;
}
