#pragma once

typedef struct {
	T data;
	struct node *next;
}node;

typedef struct {
	struct node *first;
	struct node *last;
}queue_c;

static queue_c queueref;

int count; //counts the number of nodes in queue.

int enqueue(T node);
int dequeu(T *node);
void printQueue();
int deleteNode(T data);