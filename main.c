#include <stdio.h>

#include <string.h>

#include "include/hash.h"
#include "include/map.h"

int main(){ 
    Hashmap map = initMap();
    char name[100];
    int value;
    
    while(1){
        printf("Name: ");
        fgets(name,100,stdin);
        name[strcspn(name,"\n")] = '\0';

        printf("Value: ");
        scanf("%d",&value);
        getchar();


    }
}