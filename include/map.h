#ifndef MAP
#define MAP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char key[100];
    int value;
}MapEntry;

typedef struct Node{
    char key[100];
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
Hashmap initMapArray_impl(MapEntry *entries, size_t count);

#define initMapOf(...) \
    (sizeof((MapEntry[]){__VA_ARGS__}) == sizeof(MapEntry) && #__VA_ARGS__[0] == '\0') ? \
    initMapArray_impl(NULL, 0) : \
    initMapArray_impl((MapEntry[]){__VA_ARGS__}, sizeof((MapEntry[]){__VA_ARGS__}) / sizeof(MapEntry))

#endif