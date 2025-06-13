#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h" //Aquí llamo al.h
//Hacer la estructura para un nodo de la lista que enlacé
typedef struct Node {
    int data; //valor del nodo
    struct Node* next;//puntero al siguiente nodo
} Node;

static Node* head = NULL; //Puntero que va al inicio de la lista
static unsigned int size = 0; //Contador 
//Inicializó la lista
void linked_list_init() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    size = 0;
}
//Agrega un nodo al final de la lista
int linked_list_append(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return -1;//Da un error de memoria
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;//Si hay lista vacia el nuevo nodo es el primer elemento
    } else {
        //Va a recorrer hasta el ultimo nodo
        Node* current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }

    size++;
    return 0;
}
//Agrega un nodo al fianl
int linked_list_prepend(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = head; //El nuevo va a lo que estaba primero
    head = new_node;

    size++;
    return 0;
}
//Elimina el primer nodo que me dan
int linked_list_remove(int data) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            size--;
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}
//Verifica si un valor esta en la lista
int linked_list_contains(int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data)
            return 1;
        current = current->next;
    }
    return 0;
}
//Devuelve el numero de elementos en la lista
unsigned int linked_list_size() {
    return size;
}
//Imprime todos los elementos de la lista
void linked_list_print() {
    Node* current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}