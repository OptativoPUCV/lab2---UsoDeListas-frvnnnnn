#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
    List* L = create_list();
    for (unsigned short i= 1;i<= 10;i++) {
        int* elemento=(int*)malloc(sizeof(int));
        *elemento=i;
        push(L,elemento);
    }

    return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
    int suma= 0;
    int *dato=(int*)first(L);
    while (dato != NULL) {
        suma+=*dato;
        dato= (int*)next(L);
    }
    return suma;
}


/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
  int *dato;
  dato = (int*)first(L);
  while (dato != NULL)
    {
      if (*dato==elem)
      {
        popCurrent(L);
      }
      dato = (int*)next(L);
      
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
  Stack* P3 = create_stack();
  void* dato=first(P1);
  
  while ((dato = next(P1))!=NULL)
    {
      push(P3,dato);
    }
  push(P2, dato);
  while ((dato = pop(P3))!=NULL)
    {
      push(P2,dato);
    }
  push(P2, dato);
  
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  void* dato;
  int pos=0;
  Stack* P1 = create_stack();
  while (cadena[pos] != '\0')
    {
      if (cadena[pos] == '(' || cadena[pos] == '[' || cadena[pos] == '{')
      {
        push(P1, (void*)&cadena[pos]);
      }
      else {
        dato = pop(P1);
        if (dato == NULL)
          return 0;
        else if (*(char*)dato == '(' && cadena[pos] != ')')
          return 0;
        else if (*(char*)dato == '[' && cadena[pos] != ']')
          return 0;
        else if (*(char*)dato == '{' && cadena[pos] != '}')
          return 0;
      }
      pos++;
    }
    
    if (P1!=NULL)
      return 0;  // Paréntesis balanceados
    else
      return 1;  // Paréntesis no balanceados
}



