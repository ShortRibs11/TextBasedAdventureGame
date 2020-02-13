#include <stdio.h>
#include "object.h"
#include "toggle.h"
static const char *tags0[] = { "field", NULL};
static const char *tags1[] = { "cave", NULL};
static const char *tags2[] = { "silver", "coin", "silver coin", NULL};
static const char *tags3[] = { "gold", "coin", "gold coin", NULL};
static const char *tags4[] = { "guard", "burly guard", NULL};
static const char *tags5[] = { "yourself", NULL};
static int condition6(void)  { return guard->health == 0 || silver->location == guard; }
static const char *tags6[] = { "east", "entrance", NULL};
static int condition7(void)  { return guard->health > 0 && silver->location != guard; }
static const char *tags7[] = { "east", "entrance", NULL};
static const char *tags8[] = { "west", "exit", NULL};
static const char *tags9[] = { "west", "north", "south", "forest", NULL};
static const char *tags10[] = { "east", "north", "rock", NULL};
static const char *tags11[] = { "backroom", NULL};
static const char *tags12[] = { "east", "west", "south", "rock", NULL};
static const char *tags13[] = { "south", "door", "doorway", NULL};
static const char *tags14[] = { "south", "door", "doorway", NULL};
static const char *tags15[] = { "north", "door", "doorway", NULL};
static const char *tags16[] = { "north", "door", "doorway", NULL};
static const char *tags17[] = { "box", "wooden box", NULL};
static const char *tags18[] = { "box", "wooden box", NULL};
static const char *tags19[] = { "box", "wooden box", NULL};
static const char *tags20[] = { "key", "tiny key", NULL};
static const char *tags21[] = { "lamp", NULL};
static const char *tags22[] = { "lamp", NULL};

static int alwaysTrue(void) { return 1; }

OBJECT objs[] = {
	{	/* 0 = field */
		alwaysTrue,
		 "an open field",
		tags0,
		NULL,
		NULL,
		NULL,
		 "The field is a nice and quiet place under a clear blue sky.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		 1
	},
	{	/* 1 = cave */
		alwaysTrue,
		 "a little cave",
		tags1,
		NULL,
		NULL,
		NULL,
		 "The cave is just a cold, damp, rocky chamber.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 2 = silver */
		alwaysTrue,
		 "a silver coin",
		tags2,
		 field,
		NULL,
		NULL,
		 "The coin has an eagle on the obverse.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 3 = gold */
		alwaysTrue,
		 "a gold coin",
		tags3,
		 openBox,
		NULL,
		NULL,
		 "The shiny coin seems to be a rare and priceless artifact.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 4 = guard */
		alwaysTrue,
		 "a burly guard",
		tags4,
		 field,
		NULL,
		NULL,
		 "The guard is a really big fellow.\n",
		 "He has",
		"You can't get much closer than this.\n",
		99,
		 20,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 5 = player */
		alwaysTrue,
		 "yourself",
		tags5,
		 field,
		NULL,
		NULL,
		 "You would need a mirror to look at yourself.\n",
		 "You have",
		"You can't get much closer than this.\n",
		99,
		 20,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 6 = intoCave */
		condition6,
		 "a cave entrance to the east",
		tags6,
		 field,
		 cave,
		 cave,
		 "The entrance is just a narrow opening in a small outcrop.\n",
		"You see",
		 "You walk into the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 7 = intoCaveBlocked */
		condition7,
		 "a cave entrance to the east",
		tags7,
		 field,
		NULL,
		 cave,
		 "The entrance is just a narrow opening in a small outcrop.\n",
		"You see",
		 "The guard stops you from walking into the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 8 = exitCave */
		alwaysTrue,
		 "an exit to the west",
		tags8,
		 cave,
		 field,
		 field,
		 "Sunlight pours in through an opening in the cave's wall.\n",
		"You see",
		 "You walk out of the cave.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 9 = wallField */
		alwaysTrue,
		 "dense forest all around",
		tags9,
		 field,
		NULL,
		NULL,
		 "The field is surrounded by trees and undergrowth.\n",
		"You see",
		 "Dense forest is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 10 = wallCave */
		alwaysTrue,
		 "solid rock all around",
		tags10,
		 cave,
		NULL,
		NULL,
		 "Carved in stone is a secret password abccd'.\n",
		"You see",
		 "Solid rock is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 11 = backroom */
		alwaysTrue,
		 "a backroom",
		tags11,
		NULL,
		NULL,
		NULL,
		 "The room is dusty and messy.\n",
		"You see",
		"You can't get much closer than this.\n",
		99,
		 9999,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 12 = wallBackroom */
		alwaysTrue,
		 "solid rock all around",
		tags12,
		 backroom,
		NULL,
		NULL,
		 "Trendy wallpaper covers the rock walls.\n",
		"You see",
		 "Solid rock is blocking the way.\n",
		99,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 13 = openDoorToBackroom */
		alwaysTrue,
		 "an open door to the south",
		tags13,
		NULL,
		 backroom,
		 backroom,
		 "The door is open.\n",
		"You see",
		 "You walk through the door into a backroom.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		 toggleBackdoor,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 14 = closedDoorToBackroom */
		alwaysTrue,
		 "an closed door to the south",
		tags14,
		 cave,
		NULL,
		 backroom,
		 "The door is closed.\n",
		"You see",
		 "The door is closed.\n",
		99,
		0,
		0,
		 toggleBackdoor,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 15 = openDoorToCave */
		alwaysTrue,
		 "an open door to the north",
		tags15,
		NULL,
		 cave,
		 cave,
		 "The door is open.\n",
		"You see",
		 "You walk through the door into a backroom.\n",
		99,
		0,
		0,
		 isAlreadyOpen,
		 toggleBackdoor,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 16 = closedDoorToCave */
		alwaysTrue,
		 "an closed door to the north",
		tags16,
		 backroom,
		NULL,
		 cave,
		 "The door is closed.\n",
		"You see",
		 "The door is closed.\n",
		99,
		0,
		0,
		 toggleBackdoor,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 17 = openBox */
		alwaysTrue,
		 "a wooden box",
		tags17,
		NULL,
		NULL,
		NULL,
		 "The box is open.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		 10,
		0,
		 isAlreadyOpen,
		 toggleBox,
		 isStillOpen,
		 isAlreadyOpen,
		0
	},
	{	/* 18 = closedBox */
		alwaysTrue,
		 "a wooden box",
		tags18,
		NULL,
		NULL,
		NULL,
		 "The box is closed.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		 toggleBox,
		 isAlreadyClosed,
		 toggleBoxLock,
		 isAlreadyUnlocked,
		0
	},
	{	/* 19 = lockedBox */
		alwaysTrue,
		 "a wooden box",
		tags19,
		 backroom,
		NULL,
		NULL,
		 "The box is closed.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		 isStillLocked,
		 isAlreadyClosed,
		 isAlreadyLocked,
		 toggleBoxLock,
		0
	},
	{	/* 20 = keyForBox */
		alwaysTrue,
		 "a tiny key",
		tags20,
		 cave,
		NULL,
		NULL,
		 "The key is really small and shiny.\n",
		"You see",
		"You can't get much closer than this.\n",
		 1,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 21 = lampOff */
		alwaysTrue,
		 "a lamp",
		tags21,
		 field,
		NULL,
		NULL,
		 "The lamp is off.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		0
	},
	{	/* 22 = lampOn */
		alwaysTrue,
		 "a lamp",
		tags22,
		NULL,
		NULL,
		NULL,
		 "The lamp is on.\n",
		"You see",
		"You can't get much closer than this.\n",
		 5,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked,
		 1
	}
};
