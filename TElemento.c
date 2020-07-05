#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("\nNombre: %s\n",t);

}

void asignar(TElemento* copia, TElemento original){
    strcpy((*copia),original);

}

int igual(TElemento* uno, TElemento* dos){
    return  (strcmp((*uno),dos)==0);
}

void crear(char* n, TElemento* e){
    strcpy(e,n);
}