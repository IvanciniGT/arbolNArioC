#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "simplelinkedlist.h"

typedef struct NodeNTree{
        TElemento info;
        struct NodeNTree* hijo;
        struct NodeNTree* hermano;
        struct NodeNtree* padre;
    }TNodeNTree;

typedef TNodeNTree* TNTree;


void crearArbolVacio(TNTree* a);
void anadirRaiz(TNTree* a, TElemento e);
void anadirHijo(TNTree* a, TElemento p, TElemento e);
void anadirHermano(TNTree* a, TElemento h, TElemento e);
void borrarArbol(TNTree* a);
void copiarArbol(TNTree original, TNTree* copia);
int esArbolVacio(TNTree a);
int numeroHojas(TNTree a);
int numeroNodos(TNTree a);
int altura(TNTree a);
void padre(TNTree a, TElemento e);
TLinkedList listaHijos(TNTree a);
TLinkedList listaHermanos(TNTree a);
TLinkedList listaAntepasados(TNTree a);
TLinkedList recorrido(TNTree a);
void borrarNodo(TNTree* a,TElemento e);