#include <ctype.h>
#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#include "world.h"
#include "location.h"
#include "inventory.h"
#include "inventory2.h"
#include "openclose.h"
#include "combat.h"
#include "consumables.h"
#include "onoff.h"

typedef struct {
	int (*function)(void);
	const char *pattern;
} COMMAND;

static int executeQuit(void) {
	return 0;
}

static int executeNoMatch(void) {
	const char *src = *params;
	if (*src != '\0') {
		printf("I don't know how to '");
		while (*src != '\0' && !isspace(*src)) putchar(*src++);
		printf("'.\n");
	}
	return 1;
}

int parseAndExecute(char *input) {
	static const COMMAND commands[] = {
		{executeQuit				,	"quit"},
		{executeLookAround	,	"look"},
		{executeLookAround	,	"look around"},
		{executeLook				,	"look at A"},
		{executeLook				,	"look A"},
		{executeLook				,	"examine A"},
		{executeGo					,	"go to A"},
		{executeGo					,	"go A"},
		{executeGetFrom			,	"get A from B"},
		{executeGet					,	"get A"},
		{executeExtinguish	,	"put out A"},
		{executePutIn				,	"put A in B"},
		{executePutIn				,	"drop A in B"},
		{executeDrop				,	"drop A"},
		{executeAskFrom			,	"ask A from B"},
		{executeAsk					,	"ask A"},
		{executeGiveTo			,	"give A to B"},
		{executeGive				,	"give A"},
		{executeInventory		,	"inventory"},
		{executeOpen				,	"open A"},
		{executeClose				,	"close A"},
		{executeLock				,	"lock A"},
		{executeUnlock			,	"unlock A"},
		{executeTurnOn			,	"turn on A"},
		{executeTurnOff			,	"turn off A"},
		{executeTurnOff			,	"shut A off"},
		{executeTurnOff			,	"shut off A"},
		{executeClose				,	"shut A"},
		{executeTurnOn			,	"turn A on"},
		{executeTurnOff			,	"turn A off"},
		{executeLight				,	"light A"},
		{executeExtinguish	,	"extinguish A"},
		{executeFight				,	"fight A"},
		{executeFight				,	"attack A"},
		{executeFight				,	"kill A"},
		{executeFight				,	"hit A"},
		{executeEat				,	"eat A"},
		{executeDrink				,	"drink A"},
		{executeNoMatch			,	"A"}
	};
	const COMMAND *cmd;
	for (cmd = commands; !matchCommand(input, cmd->pattern); cmd++);
	int exitCode = (*cmd->function)();
	if (exitCode) {
		if (isLookAroundNeeded()) {
			printf("\n");
			executeLookAround();
		}
		if (isWorldUpdateNeeded()) {
			printf("\n");
			worldUpdate();
		}
	}
	return exitCode;
}
