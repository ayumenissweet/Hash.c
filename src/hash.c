#include "../include/hash.h"


uint64_t hash(char *str){
    uint64_t hash = 5381;
    int c;
    while(c = *str++){
        hash = ((hash << 5) + hash) + c; //multiply by 33, add theh ash, and then the character
    }

    return hash;
}

int getRandomIndex(uint64_t num){
    return num % 16;
}
