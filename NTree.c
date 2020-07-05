#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"

int maximo(int a, int b){
    return a>b?a:b;
}

TNodeNTree* buscarNodo(TNodeNTree* actual, TElemento elemento){
    // Buscamos el elemento al que añadirle un hijo
    // Si soy vacio o soy yo
    if(esArbolVacio(actual) || igual(&(actual->info),&elemento))
        return actual;
    // Mirar en los hijos
    TNodeNTree* resultado = buscarNodo(actual->hijo, elemento);
    if(esArbolVacio(resultado)){
        // No lo he encontrado entre mis hijos.
        // Le pregunto a mi hermano
        resultado = buscarNodo(actual->hermano, elemento);
    }
    return resultado;
}

TNodeNTree* crearNodo(TNodeNTree* padre, TElemento info){
    TNodeNTree* nodo = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    asignar(&nodo->info, info);
    //asignar(nodo->info, &info);
    nodo->hermano=NULL;
    nodo->hijo=NULL;
    nodo->padre=padre;

    return nodo;
}



TNTree crearArbolVacio(TNTree* a){
    *a=NULL;
    return *a;
}
void anadirRaiz(TNTree* a, TElemento info){
    TNodeNTree* nodo = crearNodo(NULL, info);
    *a=nodo;
}

void anadirHijo(TNTree* a, TElemento infoPadre, TElemento infoHijo){
    TNodeNTree* padre = buscarNodo(*a, infoPadre);
    // Vamos a ver si he encontrado algo
    if(padre != NULL){
        TNodeNTree *nodo = crearNodo(padre, infoHijo);
        // Busco el ultimo hijo y le añado un hermnano
        TNodeNTree* ultimoHijo = padre -> hijo;
        if(ultimoHijo==NULL){
            padre->hijo=nodo;
        }else {
            while (ultimoHijo->hermano != NULL)
                ultimoHijo = ultimoHijo->hermano;
            ultimoHijo->hermano = nodo;
        }
    }
}
void anadirHermano(TNTree* a, TElemento infoHermano, TElemento infoNuevo){
    TNodeNTree* hermano = buscarNodo(*a, infoHermano);
    // Vamos a ver si he encontrado algo
    if(hermano != NULL){
        // Busco el ultimo a ese nivel
        while (hermano-> hermano != NULL)
            hermano = hermano -> hermano;
        TNodeNTree* nodo = crearNodo(hermano -> padre, infoNuevo);
        hermano-> hermano=nodo;
    }
}

void borrarArbol(TNTree* a){
    if(!esArbolVacio(*a)){
        borrarArbol(&((*a)->hermano));
        borrarArbol(&((*a)->hijo));
        free(*a);
    }
    *a=NULL;
}

TNodeNTree* copiarNodo(TNodeNTree* original, TNodeNTree* padre){
    // Info
    TElemento* info =crear(original->info.info);
    // Creamos la copia del elemento
    TNodeNTree* nuevo =crearNodo( padre, *info);
    if(!esArbolVacio(original-> hermano)){
        // Tengo que copiar el hemano
        TNodeNTree *hermano = copiarNodo(original->hermano, hermano);
        nuevo->hermano=hermano;
    }
    if(!esArbolVacio(original-> hijo)){
        // Tengo que copiar el hemano
        TNodeNTree* hijo = copiarNodo(original->hijo, hijo);
        nuevo->hijo=hijo;
    }
    return nuevo;
}

void copiarArbol(TNTree original, TNTree* copia){
    if (esArbolVacio(original)){
        crearArbolVacio(copia);
    }
    else{
        TNodeNTree* nuevo =copiarNodo(original, NULL);
        *copia = nuevo;
    }
}
int esArbolVacio(TNTree a){
    return (a)==NULL;
}
int numeroHojas(TNTree a){
    printf("%s\n",a->info.info);
    if (esArbolVacio(a)){
        return 0;
    }else{
        int hojasHermano=a->hermano!=NULL ? numeroHojas(a->hermano):0;
        int hojasHijos=a->hijo!=NULL ? numeroHojas(a->hijo):0;
        if (a->hijo==NULL){
            hojasHijos=1;
            printf("_____%s\n",a->info.info);
        }
        return hojasHijos+hojasHermano;
    }
}
int numeroNodos(TNTree a){
    if (esArbolVacio(a)){
        return 0;
    }else{
        int numeroDescendientes = numeroNodos(a->hijo);
        int numeroSobrinos = numeroNodos(a->hermano);
        return 1 + numeroDescendientes+ numeroSobrinos;
    }
}
//  A
// B C
int altura(TNTree a){
    if (esArbolVacio(a)){
        return 0;
    }else{
        int miAltura=1+altura(a->hijo);
        int alturaHermano=0;
        if(a->hermano!=NULL)
            alturaHermano=altura(a->hermano);
        return maximo(miAltura,alturaHermano);
    }
}
TElemento* parent(TNTree arbol, TElemento elemento){
    TNodeNTree* nodo=buscarNodo(arbol,  elemento);
    if(esArbolVacio(nodo)){
        return NULL;
    }
    return &(nodo->padre->info);
}
TLinkedList listaHijos(TNTree arbol, TElemento elemento) {
    TNodeNTree *nodo = buscarNodo(arbol, elemento);
    TLinkedList *list = (TLinkedList *) malloc(1 * sizeof(TLinkedList));
    crearVacia(list);

    if (!esArbolVacio(nodo)) {
        TNodeNTree *aux;
        aux = nodo->hijo;
        TElemento* e=crear(aux->info.info);
        insertar(*e, list);
        while (aux->hermano != NULL) {
            aux = aux->hermano;
            asignar(e, (aux->info));
            insertarFinal(*e, list);
        }
    }
    return *list;
}
TLinkedList listaHermanos(TNTree arbol, TElemento elemento) {
    TElemento* padre=parent(arbol,elemento);
    TLinkedList lista= listaHijos(arbol, *padre);
    eliminar (elemento, &lista);
    return lista;
}
TLinkedList listaAntepasados(TNTree arbol, TElemento elemento){
    TLinkedList* lista = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    TNodeNTree *nodo = buscarNodo(arbol, elemento);
    crearVacia(lista);
    TNodeNTree* aux;
    aux=nodo;
    while(aux->padre!=NULL){
        aux=aux->padre;
        insertar(aux->info, lista);
    }
    return *lista;
}   
TLinkedList recorrido(TNTree a){
    TLinkedList* list = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    crearVacia(list);
    insertarFinal(a->info, list);

    if(a->hermano!=NULL){
        concatenar(list, recorrido(a->hermano));
    }
    if(a->hijo!=NULL){
        concatenar(list, recorrido(a->hijo));
    }
    return *list;
}
void borrarNodo(TNTree* arbol,TElemento elemento){
    TNodeNTree *nodo = buscarNodo(*arbol, elemento);
    if(esArbolVacio(nodo)) return;
    if(nodo->padre->hijo == nodo){
        // Esto es solo si soy el primer hijo
        if(nodo->hermano != NULL){
            nodo->padre->hijo=nodo->hermano;
        }else{
            // No tengo hermanos
            nodo->padre->hijo = NULL;
        }
    }else{
        // No soy el primogenito
        TNodeNTree* anterior=nodo->padre->hijo;
        while(anterior->hermano!=nodo){
            // No es mi hermano anterior
            anterior=anterior->hermano;
        }
        // Ya he localizado al hermano anterior
        if(nodo->hermano==NULL) {
            // Era el ultimo de la familia
            anterior->hermano=NULL;
        }else{
            // No era ni primero ni ultimo
            anterior->hermano=nodo->hermano;
        }
    }
    

    free(nodo);
    nodo=NULL;
}
 