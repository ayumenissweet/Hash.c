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

        if(!strcmp(name,"break"))
            break;
        
        printf("Value: ");
        scanf("%d",&value);
        getchar();

        set(&map,name,value);

        displayMap(map);
    }

    while(1){
        printf("Name to delete: ");
        fgets(name,100,stdin);
        name[strcspn(name,"\n")] = '\0';

        removeMap(&map,name);
        displayMap(map);
    }
}