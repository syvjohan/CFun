#pragma once

//Struct
typedef struct person;

//Functions
void enqueue(struct person *p);
void dequeue(struct person *p);
void get_person(struct person *p, int pos);
int get_number_of_person();
int empty();
int full();

//Variables
static int tail;
static int head;
static int numbOfElements;

