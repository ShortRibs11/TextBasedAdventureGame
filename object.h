
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
	const char 		*(*customClimb)(void);
	const char 		*(*customJumpOff)(void);
	const char		*(*update)(void);
	int 					lightSource;
	const char 		*integrated;
} OBJECT;

extern OBJECT objs[];

#define player	(objs + 0)
#define deku_lobby	(objs + 1)
#define deku_level2	(objs + 2)
#define deku_level3	(objs + 3)
#define deku_basementPool	(objs + 4)
#define deku_lobbyLadder	(objs + 5)
#define deku_downFrom2ndFloor	(objs + 6)
#define deku_2ndLadder	(objs + 7)
#define deku_downToSecondFloor	(objs + 8)
#define deku_jumpFromTopWeb	(objs + 9)
#define deku_jumpFromTop	(objs + 10)
#define deku_basementLadder	(objs + 11)
#define deku_webPitLobby	(objs + 12)
#define deku_weblessPitLobby	(objs + 13)
#define deku_wallLobby	(objs + 14)

#define endOfObjs	(objs + 15)

#define validObject(obj)	((obj) != NULL && (*(obj)->condition)())

#define forEachObject(obj)	for (obj = objs; obj < endOfObjs; obj++) if (validObject(obj))
