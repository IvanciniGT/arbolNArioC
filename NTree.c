#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"

/*
 *                           A
 *             B                           C
 *         E        F                   G     H
 */
// Nos pasan A y H
    // Nos pasan B y H
        // Nos pasan E y H
            // Nos pasan NULL y H ACABO Devolviendo NULL
            // Nos pasan F y H
                // Miro el hijo de F: NULL. Devuelve NULL
                // Miro el hermano de F: NULL. Devuelve NULL

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
    asignar(nodo->info, &info);
    nodo->hermano=NULL;
    nodo->hijo=NULL;
    nodo->padre=padre;
    return nodo;
}

int max(int a, int b){
    return a>b?a:b;
}

/*
        while (nodo != NULL) {
            // Miramos si yo soy el padre
            if (nodo->info != padre) {
                // Hemos encontrado el padre
                anadirHijo(&nodo->hijo, padre, hijo);
                return;
            }
            // Vamos recorriendo los elementos del nivel a ver si está aqui el padre

            // En este nivel no estaba el padre
            if (aux3->hijo != NULL) {
                anadirHijo(&aux3->hijo, padre, hijo);
            }
            if (aux3->hermano != NULL) {
                anadirHijo(&aux3->hermano, padre, hijo);
            }
            if (nodo->info != padre) {
                // Hemos encontrado el padre
                anadirHijo(&nodo->hijo, padre, hijo);
                return;
            }
            nodo = nodo->hermano;
        }
    }
}
*/
void crearArbolVacio(TNTree* a){
    *a=NULL;
}
void anadirRaiz(TNTree* a, TElemento info){
    TNodeNTree* nodo = crearNodo(NULL, info);
    *a=nodo;
}

void anadirHijo(TNTree* a, TElemento infoPadre, TElemento infoHijo){
    TNodeNTree* padre = buscarNodo(*a, infoPadre);
    // Vamos a ver si he encontrado algo
    if(padre != NULL){
        // Busco el ultimo hijo y le añado un hermnano
        TNodeNTree* ultimoHijo = padre -> hijo;
        while (ultimoHijo-> hermano != NULL)
            ultimoHijo = ultimoHijo -> hermano;
        TNodeNTree* nodo = crearNodo(padre, infoHijo);
        ultimoHijo -> hermano=nodo;
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
    a=NULL;
}

TNodeNTree* copiarNodo(TNodeNTree* original, TNodeNTree* padre){
    // Info
    TElemento* info =&(original->info);
    // Creamos la copia del elemento
    TNodeNTree* nuevo =crearNodo( padre, *info);
    if(!esArbolVacio(original-> hermano)){
        // Tengo que copiar el hemano
        TNodeNTree *hermano = NULL;
        copiarNodo(original->hermano, hermano);
        nuevo->hermano=hermano;
    }
    if(!esArbolVacio(original-> hijo)){
        // Tengo que copiar el hemano
        TNodeNTree* hijo = NULL;
        copiarNodo(original->hijo, hijo);
        nuevo->hijo=hijo;
    }
    return nuevo;
}
/*
 *              A                                A'
 *          B      C                        B'       C'?
 *        D   E
 */
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
    if (esArbolVacio(a)){
        return 0;
    }else if (a->hijo==NULL){
        return 1;
    }else{
        return numeroHojas(a->hijo) + numeroHojas(a->hermano);
    }
}
int numeroNodos(TNTree a){
    if (esArbolVacio(a)){
        return 0;
    }else{
        return 1 + numeroNodos(a->hijo)+ numeroNodos(a->hermano);
    }
}
int altura(TNTree a){
    if (esArbolVacio(a)){
        return 0;
    }else{
        int miAltura=altura(a->hijo);
        int alturaHermano=altura(a->hermano);
        return 1+max(miAltura,alturaHermano);
    }
}
TElemento* padre(TNTree arbol, TElemento elemento){
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
        while (aux->hermano != NULL) {
            aux = aux->hermano;
            asignar(*e, &(aux->info));
            insertar(*e, list);
        }
    }
    return *list;
}
TLinkedList listaHermanos(TNTree arbol, TElemento elemento) {
    TElemento* _padre=padre(arbol,elemento);
    TLinkedList lista= listaHijos(arbol, *_padre);
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
        asignar(elemento, &(aux->info));
        aux=aux->padre;
        insertar(elemento, lista);
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
            // Era hijo unico!!!!
            nodo->padre->hijo = NULL;
        }
    }else{
        // No soy el primogenito ;)
        TNodeNTree* anterior=nodo->padre->hijo;
        while(anterior->hermano!=nodo){
            // No es mi hermano anterior... sigue rascando
            anterior=anterior->hermano;
        }
        // Aqui si ya tengo al hermano anterior
        if(nodo->hermano==NULL) {
            // Era el ultimo de la familia... me borro
            anterior->hermano=NULL;
        }else{
            // Yo estaba por en madio...
            anterior->hermano=nodo->hermano;
        }
    }
    free(nodo);
    nodo=NULL;
}
 