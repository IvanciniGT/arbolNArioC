#include <stdio.h>
#include <string.h>

typedef struct Elemento{
    char info [20];
}TElemento;


void print (TElemento t);

void asignar(TElemento copia, TElemento* original);

int igual(TElemento* uno, TElemento* dos);

TElemento* crear(char* n);
