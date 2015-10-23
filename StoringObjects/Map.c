#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> //memcpy

#include "tree.h"

#ifdef __cplusplus
#define ALLOC_STRUCT(s, n) ((s*)MALLOC(n * sizeof(s)))
#else
#define ALLOC_STRUCT(s, n) (MALLOC(n * sizeof(s)))
#endif

void setDefault(void) {
	tree.len = 0;
	tree.maxSize = INCREASE(0);
	tree.obj = ALLOC_STRUCT(object_t, tree.maxSize);
	tree.obj->obj = ALLOC_STRUCT(object_t, tree.maxSize);
}

void freeMem(void) {
	if (tree.obj != NULL) {
		free(tree.obj);
		tree.obj = NULL;
	}
}

void increaseArr(void) {
	int oldSize = tree.maxSize;
	tree.maxSize = INCREASE(tree.maxSize);

	object_t *tmpObj = tree.obj;
	tree.obj = ALLOC_STRUCT(object_t, tree.maxSize);

	int i;
	for (i = 0; i != oldSize; ++i) {
		tree.obj[i] = tmpObj[i];
	}

	free(tmpObj);
	tmpObj = NULL;
}

int concatAppend(object_t o, int lenArgs, int position) {
	if (position <= (tree.len + 1) && position >= 0) {

		if (tree.maxSize == tree.len) {
			increaseArr();
		}

		object_t *tmpObj = NULL;
		//Insert in middle.
		if (tree.len != 0 && position != tree.len) {
			tmpObj = ALLOC_STRUCT(object_t, tree.len);
			int j;
			int k = 0;
			for (j = position; j != tree.len; ++j, ++k) {
				tmpObj[k] = tree.obj[j];
			}
		}

		tree.obj[position].name = o.name;
		tree.obj[position].type = o.type;
		tree.obj[position].value = o.value;
		tree.obj[position].objDeep = lenArgs;

		int i;
		for (i = 0; i != lenArgs; ++i) {
			tree.obj[position].obj[i].name = o.obj[i].name;
			tree.obj[position].obj[i].type = o.obj[i].type;
			tree.obj[position].obj[i].value = o.obj[i].value;
		}

		//Insert in middle.
		if (tree.len != 0 && position != tree.len) {
			int k = 0;
			int j;
			for (j = position + 1; j <= tree.len; ++j, ++k) {
				tree.obj[j] = tmpObj[k];
			}

			free(tmpObj);
		}
		tmpObj = NULL;
		++tree.len;
	}
	else {
		//fail wrong position.
		return 0;
	}
	return 1;
}

int concatRemove(int position) {
	if (position < (tree.len + 1) && position >= 0) {

		object_t *tmpObj = NULL;
		//Remove in middle.
		if (position != 0 && position != tree.len) {
			tmpObj = ALLOC_STRUCT(object_t, tree.len);
			int j;
			int k = 0;
			for (j = position; j != tree.len; ++j, ++k) {
				tmpObj[k] = tree.obj[j];
			}
		}

		tree.obj[position].obj = NULL;

		//Remove in middle.
		if (position != 0 && position != tree.len) {
			int k = 0;
			int j;
			for (j = position - 1; j <= tree.len; ++j, ++k) {
				tree.obj[j] = tmpObj[k];
			}

			free(tmpObj);
		}
		tmpObj = NULL;
		--tree.len;
	}
	else {
		//fail wrong position.
		return 0;
	}
	return 1;
}

void insertFront(object_t obj, int lenArgs) {
	insertAt(obj, lenArgs, 0);
}

void insertBack(object_t obj, int lenArgs) {
	insertAt(obj, lenArgs, tree.len);
}

void insertAt(object_t obj, int lenArgs, int position) {
	int res = concatAppend(obj, lenArgs, position);
	assert(res == 1);
}

void removeFront(void) {
	removeAt(0);
}

void removeBack(void) {
	removeAt(tree.len);
}

void removeAt(int position) {
	int res = concatRemove(position);
	assert(res == 1);
}

int getSize(void) {
	return tree.len;
}

void print(void) {
	int i;
	for (i = 0; i != tree.len; ++i) {
		printf("%s\n", tree.obj[i].name);
	}
	printf("\n\n");
}

