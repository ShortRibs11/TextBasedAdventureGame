#define MAX_PARAMS  26

extern const char *params[];

#define paramByLetter(letter)   (params + (letter) - 'A')

extern int matchCommand(const char *src, const char *pattern);
