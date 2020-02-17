extern const char *cannotBeOpened(void);
extern const char *cannotBeClosed(void);
extern const char *cannotBeLocked(void);
extern const char *cannotBeUnlocked(void);

extern const char *isAlreadyOpen(void);
extern const char *isAlreadyClosed(void);
extern const char *isAlreadyLocked(void);
extern const char *isAlreadyUnlocked(void);

extern const char *isStillOpen(void);
extern const char *isStillLocked(void);

extern const char *cannotTurnOn(void);
extern const char *cannotTurnOff(void);
extern const char *isAlreadyOn(void);
extern const char *isAlreadyOff(void);

extern const char *cannotLight(void);
extern const char *cannotExtinguish(void);
extern const char *isAlreadyLit(void);
extern const char *isAlreadyExtinguished(void);

extern void toggleReplace(OBJECT *old, OBJECT *new);
