#include "../include/map.h"

Hashmap initMap(){
    Hashmap map;
    map.loadFactor = 0;
    for(int i = 0; i < 16; i++){
        map.heads[i] = NULL;
    }

    return map;
}

void displayMap(Hashmap map){
    for(int i = 0; i < 16; i++){
        if(!map.heads[i]) continue;
        printf("[%d] : %s, %d\n",i,map.heads[i]->key,map.heads[i]->value);
    }
    printf("%d elements\n",map.loadFactor);
}