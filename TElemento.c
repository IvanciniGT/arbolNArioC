#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("\nNombre: %s\n",t);

}

void asignar(TElemento copia, TElemento* original){
    strcpy(copia.info,original->info);

}

int igual(TElemento* uno, TElemento* dos){
    return strcmp(uno->info,dos->info)==0;
}

TElemento* crear(char* n){
    TElemento* aux = (TElemento*) malloc(sizeof(TElemento));
    strcpy(aux->info,n);
    return aux;
}