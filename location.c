#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#include "world.h"
#include "noun.h"

static int needLookAround = 0;

int executeLookAround(void) {
	if (isLit(player->location)) {
		printf("You are in %s.", player->location->description);
		OBJECT *obj;
		forEachObject(obj) {
			if (obj != player && obj->location == player->location &&
					getDistance(player, obj) < distNotHere && obj->integrated != NULL) {
				if (obj->integrated[0] != '\0') {
					printf(" %s", obj->integrated);
				}
			}
		}
		printf("\n");
	} else {
		printf("It is very dark in here.\n");
	}
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
		// Update the world
		triggerWorldUpdate();
		executeLookAround();
	}
}

int executeGo(void) {
	OBJECT *obj = getVisible("where you want to go", params[0]);
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

int isLookAroundNeeded(void) {
	int answer = needLookAround;
	needLookAround = 0;
	return answer;
}

void triggerLookAround(void) {
	needLookAround = 1;
}
