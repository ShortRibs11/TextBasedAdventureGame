
typedef struct object {
	int				 (*condition)(void);
	const char    *description;
	const char   **tags;
	struct object *location;
	struct object *destination;
	struct object *prospect;
	const char		*details;
	const char		*contents;
	const char		*textGo;
	int weight;
	int capacity;
	int health;
	const char 		*(*open)(void);
	const char 		*(*close)(void);
	const char 		*(*lock)(void);
	const char 		*(*unlock)(void);
	const char 		*(*turnOn)(void);
	const char 		*(*turnOff)(void);
	const char 		*(*light)(void);
	const char 		*(*extinguish)(void);
	const char 		*(*customGet)(void);
	const char 		*(*customFight)(void);
	const char 		*(*customAsk)(struct object*);
	const char 		*(*customEat)(void);
	const char 		*(*customDrink)(void);
	const char		*(*update)(void);
	int 					lightSource;
	const char 		*integrated;
} OBJECT;

extern OBJECT objs[];

#define field	(objs + 0)
#define cave	(objs + 1)
#define intoCaveMaze	(objs + 2)
#define exitCaveMaze	(objs + 3)
#define fromCaveMaze1to2	(objs + 4)
#define fromCaveMaze2to3	(objs + 5)
#define fromCaveMaze3to4	(objs + 6)
#define fromCaveMaze4to1	(objs + 7)
#define fromCaveMaze1to4	(objs + 8)
#define fromCaveMaze4to3	(objs + 9)
#define fromCaveMaze3to2	(objs + 10)
#define fromCaveMaze2to1	(objs + 11)
#define caveMaze1	(objs + 12)
#define caveMaze2	(objs + 13)
#define caveMaze3	(objs + 14)
#define caveMaze4	(objs + 15)
#define silver	(objs + 16)
#define gold	(objs + 17)
#define guard	(objs + 18)
#define player	(objs + 19)
#define intoCave	(objs + 20)
#define intoCaveBlocked	(objs + 21)
#define exitCave	(objs + 22)
#define wallField	(objs + 23)
#define wallCave	(objs + 24)
#define backroom	(objs + 25)
#define wallBackroom	(objs + 26)
#define openDoorToBackroom	(objs + 27)
#define closedDoorToBackroom	(objs + 28)
#define openDoorToCave	(objs + 29)
#define closedDoorToCave	(objs + 30)
#define openBox	(objs + 31)
#define closedBox	(objs + 32)
#define lockedBox	(objs + 33)
#define keyForBox	(objs + 34)
#define lampOff	(objs + 35)
#define lampOn	(objs + 36)
#define thief	(objs + 37)

#define endOfObjs	(objs + 38)

#define validObject(obj)	((obj) != NULL && (*(obj)->condition)())

#define forEachObject(obj)	for (obj = objs; obj < endOfObjs; obj++) if (validObject(obj))
