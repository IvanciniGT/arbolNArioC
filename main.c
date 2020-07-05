#include <stdio.h>
#include <stdlib.h>
#include "NTree.c"
#include "simplelinkedlist.c"
#include "TElemento.c"
//#include "NTree.c"

int main(){
    TNTree a;
    TNTree b;
    crearArbolVacio(&a);
    crearArbolVacio(&b);
    anadirRaiz(&a, "Alfonso");
    anadirHijo(&a, "Alfonso", "Miguel");
    anadirHermano(&a, "Miguel", "Jeremias");
    anadirHermano(&a, "Miguel", "Susana");
    anadirHermano(&a, "Miguel", "Laura");
    anadirHermano(&a, "Miguel", "Pepe");
    borrarNodo(&a, "Pepe");
    copiarArbol(a, &b);
    borrarArbol(&a);
    printf("%d", esArbolVacio(a));
    anadirHijo(&b, "Miguel", "Simon");
    anadirHijo(&b, "Simon", "Ana");
    anadirHijo(&b, "Jeremias", "Alberto");
    anadirHermano(&a, "Alberto", "Jesus");
    anadirHermano(&a, "Alberto", "Maria");
    anadirHijo(&b, "Alberto", "Irene");
    anadirHijo(&b, "Alberto", "Felipe");
    anadirHijo(&b, "Irene", "Gema");
    anadirHijo(&b, "Irene", "Angel");
    anadirHijo(&b, "Irene", "Luis");
    anadirHijo(&b, "Maria", "Lucia");
    anadirHijo(&b, "Maria", "Andres");
    anadirHijo(&b, "Andres", "Christian");
    anadirHijo(&b, "Andres", "Daniel");
    anadirHijo(&b, "Susana", "Pedro");
    anadirHermano(&b, "Pedro", "Iker");
    anadirHijo(&b, "Pedro", "Patricia");
    anadirHijo(&b, "Patricia", "Joel");
    anadirHijo(&b, "Laura", "Esther");
    anadirHermano(&b, "Esther", "Guadalupe");
    anadirHermano(&b, "Guadalupe", "Emilio");
    anadirHijo(&b, "Esther", "Juan");
    anadirHermano(&b, "Juan", "Roberto");
    anadirHermano(&b, "Juan", "Cesar");
    anadirHermano(&b, "Juan", "Silvia");
    anadirHijo(&b, "Roberto", "Paloma");
    anadirHijo(&b, "Roberto", "Blanca");
    anadirHijo(&b, "Roberto", "Marcos");
    anadirHijo(&b, "Silvia", "Teresa");
    printf("%d", numeroHojas(b));
    printf("%d", numeroNodos(b));
    printf("%d", altura(b));
    TElemento e;
    padre(b, e);
    print(e);
    mostrar(listaAntepasados(b));
    mostrar(listaHermanos(b));
    mostrar(listaHijos(b));
    mostrar(recorrido(b));
}