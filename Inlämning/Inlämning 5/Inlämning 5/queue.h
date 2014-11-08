//Johan Fredriksson AB5785.
#pragma once

int count; //counts the number of nodes in queue.

//This is the public functions that can be reached from menu.h
int enqueue(int node);
int dequeue(int *node);
void printQueue();
int deleteNode(int data);
void cleanUpMemory();