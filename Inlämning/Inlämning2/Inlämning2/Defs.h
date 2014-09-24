#ifndef DEFS_H
#define DEFS_H

#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new(1, __FILE__, __LINE__)
#else
#define DBG_NEW new
#endif

#define FLAGG 1
#define MINSIZE 1
#define MAXSIZE 100

typedef enum {
	GS_MAINMENU,
	GS_QUIT,
	GS_GUESSNUMBER,
	GS_THROWDICE,
	GS_FIBONACCI
} gameState;

#endif //!DEFS_H
