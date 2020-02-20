#include <stdio.h>
#include "object.h"
#include "misc.h"

/*
static OBJECT *getLocation(OBJECT *obj) {
	while (obj->location != NULL) obj = obj->location;
	return obj;
}
*/

int isLit(OBJECT *location) {
	if (location == NULL) {
		return 0;
	}
	if (location->lightSource) {
		return 1;
	}
	// Check every object
	OBJECT *obj;
	forEachObject(obj) {
		// If the object is here and generating light, the location is lit.
		if (obj->location == location && isLit(obj)) {
			return 1;
		}
	}
	return location->lightSource;
}

OBJECT *getPassage(OBJECT *from, OBJECT *to) {
	OBJECT *obj;
	forEachObject(obj) {
		if (from != NULL && obj->location == from && obj->prospect == to) {
			return obj;
		}
	}
	return NULL;
}

DISTANCE getDistance(OBJECT *from,OBJECT *to) {
	return	!validObject(to)					? distUnknownObject :
		to == from									? distSelf :
		to->location == from				? distHeld :
		!isLit(from->location) &&
		!isLit(to) && !isLit(to->prospect)		? distNotHere :
		to == from->location				? distLocation :
		to->location == from->location			? distHere :
		getPassage(from->location, to) != NULL		? distOverThere :
		!validObject(to->location)				? distNotHere :
		to->location->location == from			? distHeldContained :
		to->location->location == from->location	? distHereContained :
								  distNotHere;
}

OBJECT *actorHere(void) {
	OBJECT *obj;
	forEachObject(obj) {
		if (getDistance(player, obj) == distHere && obj->health > 0) {
			return obj;
		}
	}
	return NULL;
}

int listObjectsAtLocation(OBJECT *location) {
	int count = 0;
	OBJECT *obj;
	forEachObject(obj) {
		if (obj != player && obj->location == location &&
				getDistance(player, obj) < distNotHere && obj->integrated == NULL) {
			if (count++ == 0) {
				printf("%s\n", location->contents);
			}
			printf("%s\n", obj->description);
		}
	}
	return count;
}

int weightOfContents(OBJECT *container) {
	int sum = 0;
	OBJECT * obj;
	forEachObject(obj) {
		if (obj->location == container) {
			sum += obj->weight;
		}
	}
	return sum;
}
