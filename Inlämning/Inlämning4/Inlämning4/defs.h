#ifndef DEFS_H
#define DEFS_H

#include <crtdbg.h>

#ifdef _DEBUG
#define MALLOC(SZ) _malloc_dbg((SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define CALLOC(C, SZ) _calloc_dbg((C), (SZ), _NORMAL_BLOCK, __FILE__, __LINE__)
#define REALLOC(PTR, SZ) _realloc_dbg(PTR, SZ, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif //!_DEBUG

#define QUEUE_MAX_SIZE 10
#endif //!DEFS_H
