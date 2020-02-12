#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#include "noun.h"

int executeLookAround(void) {
	printf("You are in %s.\n", player->location->description);
	listObjectsAtLocation(player->location);
	return 1;
}

int executeLook(void) {
	OBJECT *obj = getVisible("what you want to look at", params[0]);
	switch (getDistance(player, obj)) {
		case distHereContained:
			printf("Hard to see, try to get it first.\n");
			break;
		case distOverThere:
			printf("Too far away, move closer please.\n");
			break;
		case distNotHere:
			printf("You don't see any %s here.\n", params[0]);
			break;
		case distUnknownObject:
			// already handled by getVisible
			break;
		default:
			printf("%s", obj->details);
			listObjectsAtLocation(obj);
	}
	return 1;
}

static void movePlayer(OBJECT *passage) {
	printf("%s", passage->textGo);
	if (passage->destination != NULL) {
		player->location = passage->destination;
		printf("\n");
		executeLookAround();
	}
}

int executeGo(void) {
	OBJECT *obj = getVisible("where you want to go", params[0]);
/*	if (obj == NULL) {
		// already handled by getVisible
	} else if (getPassage(player->location, obj) != NULL) {
*/
	switch (getDistance(player, obj)) {
	case distOverThere:
		movePlayer(getPassage(player->location, obj));
		break;
	case distNotHere:
		printf("You don't see any %s here.\n", params[0]);
		break;
	case distUnknownObject:
		// already handled by getVisible
		break;
	default:
		movePlayer(obj);
	}
	return 1;
}
