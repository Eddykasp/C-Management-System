#ifndef DATA_STRUCTS_H_INCLUDED
#define DATA_STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 20

typedef struct cust{
    int id;
    char name[STRING_LENGTH];
    struct cust *next;
}CUSTOMER;

//function protoypes

CUSTOMER * init_customer(int i, char n[]);
CUSTOMER * add_customer(CUSTOMER * node, int i, char n[]);
void print_customer(CUSTOMER * node);

#endif // DATA_STRUCTS_H_INCLUDED