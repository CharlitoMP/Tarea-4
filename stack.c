#include "stack.h" //aqui llamo a la biblioteca del .h

#define STACK_MAX 100 //Esta es la capacidad maxima del stack

// Lista para almacenar los elementos del stack
static unsigned int stack[STACK_MAX];

// Índice del siguiente elemento libre 
static unsigned int top = 0;

// Inicia el stack
void stack_init() {
    top = 0;
}

int stack_push(unsigned int data) {  //Esta funcion va a insertar un dato para ver si el stack está lleno
    if (top >= STACK_MAX) {
        return -1; // stack lleno
    }
    stack[top++] = data;
    return 0; // éxito
}
//Elimina y vuelve a poner el ultimo numero del stack
// Retorna -1 si está vacío
int stack_pop() {
    if (top == 0) {
        return -1; // stack vacío
    }
    return stack[--top];
}
//Retorna el numero actual de numeros en el stack
unsigned int stack_size() {
    return top;
}
//Revisa si el stack está lleno
int stack_is_full() {
    return top == STACK_MAX ? 1 : 0;
}
//Revisa si el stack vacio 
/// @return 
int stack_is_empty() {
    return top == 0 ? 1 : 0;
}