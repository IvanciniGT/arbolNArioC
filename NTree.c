#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NTree.h"


void crearArbolVacio(TNTree* a){
    *a=NULL;
}
void anadirRaiz(TNTree* a, TElemento e){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    asignar(&aux->info, e);
    aux->hermano=NULL;
    aux->hijo=NULL;
    aux->padre=NULL;
    *a=aux;

}
void anadirHijo(TNTree* a, TElemento p, TElemento e){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux2 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux3 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    copiarArbol(a, aux);
    copiarArbol(a, aux3);
    if(!esArbolVacio(a)){

        if(aux->info==p){
            
            copiarArbol(a, aux2);
            while(aux!=NULL){
                aux=aux->hermano;
            }
            anadirHermano(aux->hijo, p, e);

        }
        if(aux3->hijo!=NULL){
            anadirHijo(aux3->hijo,p, e);
        }
        if(aux3->hermano!=NULL){
            anadirHijo(aux3->hermano, p, e);
        }
    }
}
void anadirHermano(TNTree* a, TElemento h, TElemento e){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux2 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux3 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    copiarArbol(a, aux);
    copiarArbol(a, aux3);
    if(!esArbolVacio(a)){
        if(aux->info==h){
            
            copiarArbol(a, aux2);
            while(aux!=NULL){
                aux=aux->hermano;
            }
            aux2->hermano=NULL;
            asignar(aux->info, e);
            aux2->padre=aux->padre;
            aux->hermano=aux2;

        }
        if(aux3->hijo!=NULL){
            anadirHermano(aux3->hijo,h, e);
        }
        if(aux3->hermano!=NULL){
            anadirHermano(aux3->hermano, h, e);
        }
    }
}
void borrarArbol(TNTree* a){
    if(!esArbolVacio){
        destruirArbol(&((*a)->hermano));
        destruirArbol(&((*a)->hijo));
        free(*a);
        a=NULL;
    }else{
        a=NULL;
    }
}
void copiarArbol(TNTree original, TNTree* copia){
    if (esArbolVacio(original)){
        CrearArbolVacio(copia);
    }
    else{
        TNTree hijo, padre, hermano;
        copiarArbol(original->hijo,&hijo);
        copiarArbol(original->hermano,&hermano);
        TNodeNTree* aux =(TNodeNTree*)malloc(sizeof(TNodeNTree));
        aux->hijo=hijo;
        aux->hermano=hermano;
        asignar(&aux->info,(original)->info);
        *copia=aux;
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
        return numeroHojas(a->hijo)+ numeroHojas(a->hermano);
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
        return 1 + (altura(a->hermano)>altura(a->hermano->hermano)?altura(a->hermano):altura(a->hermano->hermano));
    }
}
void padre(TNTree a, TElemento e){
    e=a->info;
}
TLinkedList listaHijos(TNTree a){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TLinkedList* list = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    aux=a;
    TElemento e;
    aux=aux->hijo;
    if(!esArbolVacio(a)){
        crearVacia(list);
        while(aux->hermano!=NULL){
            asignar(e, aux->info);
            aux=aux->hermano;
            insertar(e, list);
        }
}
}
TLinkedList listaHermanos(TNTree a){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TLinkedList* list = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    crearVacia(list);
    TElemento e;
    aux=a->hermano;
    while(aux->padre!=NULL){
        asignar(e, aux->info);
        aux=aux->hermano;
        insertar(e, list);
    }
}
TLinkedList listaAntepasados(TNTree a){
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TLinkedList* list = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    crearVacia(list);
    TElemento e;
    aux=a->padre;
    while(aux->padre!=NULL){
        asignar(e, aux->info);
        aux=aux->padre;
        insertar(e, list);
    }
}   
TLinkedList recorrido(TNTree a){
    TLinkedList* list = (TLinkedList*) malloc(1*sizeof(TLinkedList));
    crearVacia(list);
    if((a->hijo=NULL) && (a->hermano=NULL)){
        insertarFinal(a->info, list);
    }else{
        if(a->hermano=NULL){
            concatenar(list, recorrido(a->hermano));
        }
        if(a->hijo=NULL){
            concatenar(list, recorrido(a->hijo));
        }
    }
    
}
void borrarNodo(TNTree* a,TElemento e){
    
    TNodeNTree* aux = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux2 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    TNodeNTree* aux3 = (TNodeNTree*) malloc(sizeof(TNodeNTree));
    copiarArbol(a, aux);
    copiarArbol(a, aux3);
    if(esArbolVacio!=0){
    if(aux->info==e){
        
        copiarArbol(a, aux2);
        aux2=aux2->hermano;
        while(aux!=NULL){
            aux=aux->hermano;
            aux2=aux2->hermano;
        }
        aux->hermano=aux2->hermano;
        aux2->hermano=NULL;
        aux2->hijo=NULL;
        aux2->padre=NULL;
    }
    if(aux3->hijo!=NULL){
        borrarNodo(aux3->hijo, e);
    }
    if(aux3->hermano!=NULL){
        borrarNodo(aux3->hermano, e);
    }
}
}
 