#ifndef MAP
#define MAP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    char key[200];
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node** heads;//TODO
    int length; // 16/32/64/...
    int loadFactor; // how many elements are filled
}Hashmap;

Hashmap initMap();
int* get(Hashmap map,char str[100]);
void set(Hashmap* map, char str[100], int value);
bool containsKey(Hashmap map, char str[100]);
bool containsValue(Hashmap map, int value);
void displayMap(Hashmap map);

#endif