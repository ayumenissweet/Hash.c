#ifndef MAP
#define MAP

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    char key[200];
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node* heads[16];//TODO
    int loadFactor;
}Hashmap;

Hashmap initMap();
void displayMap(Hashmap map);

#endif