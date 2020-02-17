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
//			printf("You drop %s.\n", obj->description);
/*			strcpy(reply, "You drop \0");
//			strcpy(buffer, obj->description);
//			snprintf(reply, BUFFER_SIZE, "You drop %s.\n", buffer);
			int i, j;
//			char *loc = obj->description;
			for (i = strlen(reply), j=0;
						(i < BUFFER_SIZE) && (obj->description[j] != '\0');
								i++, j++) {
				printf("Adding %c", obj->description[j]);
				reply[i] = obj->description[j];
			}
			reply[i] = '\0';*/
			reply = combineStrings("You drop ", combineStrings(obj->description, ".\n",
										BUFFER_SIZE), BUFFER_SIZE);
//			strcat(reply, obj->description);
//			strcat(reply, ".\n");
		} else if (to != player) {
/*			printf(to->health > 0		? "You give %s to %s.\n"
																: "You put %s in %s.\n",
					obj->description, to->description);
					*/
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
			reply = combineStrings("You pick up ",combineStrings(obj->description, ".\n",
															BUFFER_SIZE),BUFFER_SIZE);
		} else {
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
