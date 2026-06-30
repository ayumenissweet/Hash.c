#ifndef MAP
#define MAP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BASE 16
#define MEDIUM 32
#define BIG 64
#define LARGE 128
#define MASSIVE 256

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
void removeMap(Hashmap *map, char str[100]);
bool containsKey(Hashmap map, char str[100]);
bool containsValue(Hashmap map, int value);
int size(Hashmap map);
void displayMap(Hashmap map);

#endif