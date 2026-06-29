#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/types.h"

uint64_t hash(char *str){
    uint64_t hash;
    int c;
    while(c = *str++){
        hash = ((hash << 5) + hash) + c; //multiply by 33, add theh ash, and then the character
    }

    return hash;
}

int getRandomIndex(uint64_t num,int size){
    return num % size;
}


int main(){ 
    char* name;
    name = malloc(100);
    printf("Enter a name: ");
    fgets(name,100,stdin);
    int index = getRandomIndex(hash(name),2000);
    printf("Index after hashing : %d",index);

    Hashmap map;
    
}