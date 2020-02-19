#include <stdio.h>
#include <string.h>

#include "string_util.h"
#include "object.h"
#include "misc.h"

#define BUFFER_SIZE 150

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
		reply = (obj == keyForBox && (to == closedBox || to == lockedBox) ?
								"The key seems to fit the lock alright.\n" :
								"It doesn't seem to fit in.\n");
	} else if (obj->weight == to->capacity) {
		reply = "That is way too heavy.\n";
	} else if (obj->weight + weightOfContents(to) > to->capacity) {
		reply = ("That would become too heavy.\n");
	} else {
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
			obj->integrated = 0;
			reply = combineStrings("You pick up ",combineStrings(obj->description, ".\n",
															BUFFER_SIZE),BUFFER_SIZE);
		} else {
			obj->integrated = 0;
			reply = combineStrings("You get ", combineStrings(obj->description,
							combineStrings(" from ",
							combineStrings(obj->location->description, ".\n",
													BUFFER_SIZE),BUFFER_SIZE),BUFFER_SIZE),BUFFER_SIZE);
		}
		obj->location = to;
	}
	if (reply == NULL) {
		reply = "";
	}
	char *ret = reply;
	return ret;
}
