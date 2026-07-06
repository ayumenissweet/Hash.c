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
Hashmap resizeMap(Hashmap ogMap){
    Hashmap map;
    int length = ogMap.length;
    map.heads = malloc(sizeof(Node) * length * 2);
    map.loadFactor = ogMap.loadFactor;
    map.length = length * 2;
    for(int i = 0; i < length * 2; i++){
        map.heads[i] = NULL;
    }

    for(int i = 0; i < length; i++){
        if(!ogMap.heads[i]) continue;
        Node* p = ogMap.heads[i];
        while(p != NULL){
            uint64_t newHash = getRandomIndex(hash(p->key),length*2);
            Node* temp = p->next; //save this
            if(map.heads[newHash]){ //if exist insert at head
                p->next = map.heads[newHash]->next;
                map.heads[newHash] = p;
                p = temp;
                continue;
            }
            map.heads[newHash] = p;
            p->next = NULL;

            p = temp; //advance
        }
    }

    free(ogMap.heads);
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
Node* findNode(Node* head, char str[100]){
    while(head != NULL){
        if(!strcmp(head->key,str)){
            return head;
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
    int index = getRandomIndex(hash(str),16);
    if(!map.heads[index]) return NULL;
    if(!strcmp(map.heads[index]->key,str)) return &(map.heads[index]->value);
    //case : inside the linked list
    return &(findNode(map.heads[index],str)->value);
}
void set(Hashmap* map, char str[100], int value){
    int index = getRandomIndex(hash(str),map->length);
    if(!(*map).heads[index]){  //NULL
        (*map).heads[index] = createNode(str,value);
        if(!(*map).heads[index]) return;
        (*map).loadFactor++; 
        if(((double)map->loadFactor / map->length) >= 0.75){
            (*map) = resizeMap(*map);
        }
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
        map->loadFactor++;
        if(((double)map->loadFactor / map->length) >= 0.75){
            (*map) = resizeMap(*map);
        }
    }
}
void removeMap(Hashmap *map, char str[100]){
    int index = getRandomIndex(hash(str), 16);
    if(!(*map).heads[index]) return;

    if(!strcmp((*map).heads[index]->key,str)){
        if((*map).heads[index]->next == NULL){
            free(map->heads[index]);
            map->heads[index] = NULL;
        }else{
            Node* p = map->heads[index];
            map->heads[index] = map->heads[index]->next;
            free(p);
        }
    }else{
        Node* p = map->heads[index]->next;//head been handled up
        Node* prev = map->heads[index];
        while(p != NULL){
            if(!strcmp(p->key,str)){
                prev->next = p->next;
                free(p);
            }
            prev = p;
            p = p->next;
        }
    }
    map->loadFactor--;
}
int size(Hashmap map){
    printf("Map resized\n");

    return map.loadFactor;
}
bool containsKey(Hashmap map, char str[100]){
    int index = getRandomIndex(hash(str),16);
    if(!map.heads[index]) return false;
    return (findNode(map.heads[index],str) ? true : false);
}
bool containsValue(Hashmap map, int value){
    for(int i = 0; i < map.length; i++){
        if(!map.heads[i]) continue;
        Node* p = map.heads[i];
        while(p != NULL){
            if(p->value == value) return true;
            p = p->next;
        }
    }
    return false;
}
void displayMap(Hashmap map){
    for(int i = 0; i < map.length; i++){
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
Hashmap initMapArray_impl(MapEntry *entries, size_t count) {
    Hashmap map = initMap();
    for (size_t i = 0; i < count; i++) {
        set(&map,entries[i].key,entries[i].value);
    }

    return map;
}