#include <stdio.h>
#include <string.h>

typedef char TElemento [20];
    

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento* uno, TElemento* dos);

void crear(char* n, char* d, float nt, TElemento* e);
