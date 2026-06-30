#include "../include/map.h"
#include "../include/hash.h"

Hashmap initMap(){
    Hashmap map;
    map.heads = malloc(sizeof(Node) * 16);
    map.loadFactor = 0;
    map.length = 16;
    for(int i = 0; i < 16; i++){
        map.heads[i] = NULL;
    }
    return map;
}

Node* createNode(char str[100],int value){
    Node* p = (Node*) malloc(sizeof(Node));
    if(!p) {printf("Error allocating\n"); return NULL;}
    p->next = NULL;
    strcpy(p->key,str);
    p->value = value;
    return p;
}

int* findNode(Node* head, char str[100]){
    while(head != NULL){
        if(!strcmp(head->key,str)){
            return &(head->value);
        } 
        head = head->next;
    } 

    return NULL;
}

Node* getTail(Node* head){
    while(head->next != NULL){
        head = head->next;
    }

    return head;
}

int* get(Hashmap map,char str[100]){
    int index = getRandomIndex(hash(str));
    if(!map.heads[index]) return NULL;
    if(!strcmp(map.heads[index]->key,str)) return &(map.heads[index]->value);
    //case : inside the linked list
    return findNode(map.heads[index],str);
}

void set(Hashmap* map, char str[100], int value){
    int index = getRandomIndex(hash(str));
    if(!(*map).heads[index]){  //NULL
        (*map).heads[index] = createNode(str,value);
        if(!(*map).heads[index]) return;
        (*map).loadFactor++; 
    }else if(!strcmp((*map).heads[index]->key,str)){ 
        (*map).heads[index]->value = value;
    }else{
        Node* p = (*map).heads[index];
        while(p != NULL){
            if(!strcmp(p->key,str)){ //if key found, replace
                p->value = value;
                return;
            }
            p = p->next;
        }

        //case : no found keys
        getTail((*map).heads[index])->next = createNode(str,value);
    }
}

int size(Hashmap map){
    return map.loadFactor;
}

bool containsKey(Hashmap map, char str[100]){
    int index = getRandomIndex(hash(str));
    if(!map.heads[index]) return false;
    return true;
}

bool containsValue(Hashmap map, int value){
    for(int i = 0; i < map.length; i++){
        if(!map.heads[i]) continue;
        if(map.heads[i]->value == value){
            return true;
        }
    }
    return false;
}

void displayMap(Hashmap map){
    for(int i = 0; i < 16; i++){
        if(!map.heads[i]) continue;
        Node* p = map.heads[i];
        while(p != NULL){
            printf("[%d] : %s, %d",i,p->key,p->value);
            if(p->next)
                printf(" -> ");
            p = p->next;
        }
        printf("\n");
    }
    printf("%d elements\n",map.loadFactor);
}