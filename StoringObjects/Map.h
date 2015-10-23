#ifndef tree_H
#define tree_H

#include "Defs.h"

#define INCREASE(X) (X * 2 + 10)

typedef struct object_s {
	char *name;
	char *type;
	char *value;
	int objDeep;

	struct object_s *obj;
}object_t;

typedef struct tree_s {
	int maxSize;
	int len;
	object_t *obj;
} tree_t;

tree_t tree;

void setDefault(void);
void freeMem(void);

void insertFront(object_t obj, int lenArgs);
void insertBack(object_t obj, int lenArgs);
void insertAt(object_t obj, int lenArgs, int position);

void removeFront(void);
void removeBack(void);
void removeAt(int position);

void print(void);

int getSize(void);

#endif //!tree_H