typedef enum {
	distSelf,
	distHeld,
	distHeldContained,
	distLocation,
	distHere,
	distHereContained,
	distOverThere,
	distNotHere,
	distUnknownObject
} DISTANCE;

extern int isLit(OBJECT *location);
extern OBJECT *getPassage(OBJECT *from, OBJECT *to);
extern DISTANCE getDistance(OBJECT *from, OBJECT *to);
extern OBJECT *actorHere(void);
extern int listObjectsAtLocation(OBJECT *location);
extern int weightOfContents(OBJECT *container);
