#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "TElemento.h"




void insertar  (TElemento elemento, TLinkedList* lista){
  TLinkedList aux = (TLinkedList) malloc(1*sizeof(TnodoLista));
        aux->sig=*lista;
       asignar(&(aux->info),elemento);
       *lista=aux;
}
void mostrar (TLinkedList lista){
    TLinkedList aux = lista;
    while (aux!=NULL){
        print(aux->info);
        printf(" ");
        aux=aux->sig;
    }
    printf("\n");
}
TLinkedList crearVacia (TLinkedList* lista){
    *lista=NULL;
    return *lista;
}    

void insertarFinal (TElemento elemento, TLinkedList* arbol){
    if(esVacia(*arbol)){
        insertar(elemento,arbol);
    }
    else{
        TLinkedList aux = *arbol;
        while ((aux->sig)!=NULL){
            aux=aux->sig;
        }
        
        TnodoLista* auxN = (TnodoLista*) malloc(1*sizeof(TnodoLista));
        auxN->sig=NULL;
        asignar(&(auxN->info),elemento);
        aux->sig=auxN;

    }

}
int eliminar (TElemento elemento, TLinkedList* arbol){
        TLinkedList act = *arbol;
        TLinkedList ant= NULL;
        int encontrado =0;
        while ((act!=NULL)&&(!encontrado)){
            encontrado=igual(&act->info,&elemento);
            if (encontrado){
                if (ant==NULL){
                    (*arbol)=(*arbol)->sig;//por si es el primero
                }
                else{
                    ant->sig=act->sig;}
                free(act);
                }
            else{
                ant=act;
                act=act->sig;
            }
        }
        return encontrado;
}

void primero (TLinkedList arbol, TElemento* elemento){
    if(!esVacia(arbol)){
        asignar(elemento,(arbol)->info);
    }

}
void resto (TLinkedList* arbol){
    if(!esVacia(*arbol)){
        TLinkedList aux = *arbol;
        *arbol=(*arbol)->sig;
        free(aux);
    }
}
void ultimo (TLinkedList arbol, TElemento* elemento){
    if(!esVacia(arbol)){
        TLinkedList aux = arbol;
        while ((aux->sig)!=NULL){
            aux=aux->sig;
        }
       asignar(elemento,aux->info);

    }
}
void concatenar(TLinkedList* arbol1, TLinkedList arbol2){
    TLinkedList aux = arbol2;
        while ((aux)!=NULL){
            insertarFinal(aux->info,arbol1);
            aux=aux->sig;
        }
 }
int contiene (TElemento elemento, TLinkedList arbol){
     TLinkedList act = arbol;
       
        int encontrado =0;
        while ((act!=NULL)&&(!encontrado)){
            encontrado=igual(&act->info,&elemento);
            if (!encontrado){
                act=act->sig;
            }
        }
        return encontrado;
}
int esVacia (TLinkedList arbol){
    return (arbol)==NULL;
}
int longitud (TLinkedList arbol){
    TLinkedList aux = arbol;
    int longitud =0;
        while ((aux)!=NULL){
            longitud ++;
            aux=aux->sig;
        }
    return longitud;
}


void copiar(TLinkedList original, TLinkedList* copia){
    crearVacia(copia);
    if (!esVacia(original)){
        TLinkedList auxL = original;
        TLinkedList aux = (TLinkedList) malloc(1*sizeof(TnodoLista)); //crea el primer nodo
        *copia=aux;//primer nodo como cabecera
        TLinkedList ant =aux; 
        asignar(&(aux->info),auxL->info);
        auxL=auxL->sig;
        while (auxL!=NULL){
            TLinkedList aux = (TLinkedList) malloc(1*sizeof(TnodoLista));
            ant->sig=aux;
            asignar(&(aux->info),auxL->info);
            auxL=auxL->sig;
            ant=aux;
        }
        ant->sig=NULL;
    }
}
void destruir(TLinkedList* arbol){
    TLinkedList ant= NULL;
    TLinkedList act= *arbol;
    while (act!=NULL){
        ant=act;
        act=act->sig;
        free (ant);
    }
    free (act);
    *arbol=NULL;

}