//Johan Fredriksson AB5785.
#ifndef DEFS_H
#define DEFS_H

#include <crtdbg.h>

//Defining macros for program!
#ifdef _DEBUG
#define MALLOC(SZ) _malloc_dbg((SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define CALLOC(C, SZ) _calloc_dbg((C), (SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define REALLOC(PTR, SZ) _realloc_dbg(PTR, SZ, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif //!_DEBUG

#define QUEUE_MAX_SIZE 3 //The size of the queue. Only value to change whene changing the size of queue!
#define STRINGSIZE 50 // Size of the char array in the structs.

#endif //!DEFS_H
