#include <stdio.h>
#include <stdlib.h>
#include "simplelinkedlist.h"

typedef struct NodeNTree{
        TElemento info;
        struct NodeNTree* hijo;
        struct NodeNTree* hermano;
        struct NodeNTree* padre;
    }TNodeNTree;

typedef TNodeNTree* TNTree;  // Identificar el raiz


void crearArbolVacio(TNTree* a);
void anadirRaiz(TNTree* a, TElemento e);
void anadirHijo(TNTree* a, TElemento infoPadre, TElemento infoHijo);
void anadirHermano(TNTree* a, TElemento h, TElemento e);
void borrarArbol(TNTree* a);
void copiarArbol(TNTree original, TNTree* copia);
int esArbolVacio(TNTree a);
int numeroHojas(TNTree a);
int numeroNodos(TNTree a);
int altura(TNTree a);
TElemento* padre(TNTree a, TElemento e);
TLinkedList listaHijos(TNTree arbol, TElemento elemento);
TLinkedList listaHermanos(TNTree arbol, TElemento elemento) ;
TLinkedList listaAntepasados(TNTree arbol, TElemento elemento) ;
TLinkedList recorrido(TNTree a);
void borrarNodo(TNTree* a,TElemento e);