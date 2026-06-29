typedef struct Node{
    char key[200];
    int value;
    Node* next;
}Node;

typedef struct{
    Node elements[];
}Hashmap;