#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"



int main(){

    TNTree a=crearArbolVacio(&a);
    TNTree b=crearArbolVacio(&b);
     TElemento Alfonso = *crear("Alfonso");
    TElemento Miguel = *crear("Miguel");
    TElemento Simon = *crear("Simon");
    TElemento Ana = *crear("Ana");
    TElemento Jeremias = *crear("Jeremias");
    TElemento Alberto = *crear("Alberto");
    TElemento Irene = *crear("Irene");
    TElemento Gema = *crear("Gema");
    TElemento Angel = *crear("Angel");
    TElemento Luis = *crear("Luis");
    TElemento Felipe = *crear("Felipe");
    TElemento Jesus = *crear("Jesus");
    TElemento Maria = *crear("Maria");
    TElemento Lucia = *crear("Lucia");
    TElemento Andres = *crear("Andres");
    TElemento Christian = *crear("Christian");
    TElemento Daniel = *crear("Daniel");
    TElemento Susana = *crear("Susana");
    TElemento Pedro = *crear("Pedro");
    TElemento Iker = *crear("Iker");
    TElemento Patricia = *crear("Patricia");
    TElemento Joel = *crear("Joel");
    TElemento Laura = *crear("Laura");
    TElemento Esther = *crear("Esther");
    TElemento Guadalupe = *crear("Guadalupe");
    TElemento Emilio = *crear("Emilio");
    TElemento Juan = *crear("Juan");
    TElemento Roberto = *crear("Roberto");
    TElemento Cesar = *crear("Cesar");
    TElemento Silvia = *crear("Silvia");
    TElemento Paloma = *crear("Paloma");
    TElemento Blanca = *crear("Blanca");
    TElemento Marcos = *crear("Marcos");
    TElemento Teresa = *crear("Teresa");

    TLinkedList lista1, lista2, lista3, lista4;
    anadirRaiz(&a, Alfonso);
    anadirHijo(&a, Alfonso, Miguel);
    anadirHermano(&a, Miguel, Jeremias);
    anadirHermano(&a, Miguel, Susana);
    anadirHermano(&a, Miguel, Laura);
    copiarArbol(a, &b);
    borrarArbol(&a);
    printf("%d", esArbolVacio(a));
    anadirHijo(&b, Miguel, Simon);
    anadirHijo(&b, Simon, Ana);
    anadirHijo(&b, Jeremias, Alberto);
    anadirHermano(&b, Alberto, Jesus);
    anadirHermano(&b, Alberto, Maria);
    anadirHijo(&b, Alberto, Irene);
    anadirHijo(&b, Alberto, Felipe);
    anadirHijo(&b, Irene, Gema);
    anadirHijo(&b, Irene, Angel);
    anadirHijo(&b, Irene, Luis);
    anadirHijo(&b, Maria, Lucia);
    anadirHijo(&b, Maria, Andres);
    anadirHijo(&b, Andres, Christian);
    anadirHijo(&b, Andres, Daniel);
    anadirHijo(&b, Susana, Pedro);
    anadirHermano(&b, Pedro, Iker);
    anadirHijo(&b, Pedro, Patricia);
    anadirHijo(&b, Patricia, Joel);
    anadirHijo(&b, Laura, Esther);
    anadirHermano(&b, Esther, Guadalupe);
    anadirHermano(&b, Guadalupe, Emilio);
    anadirHijo(&b, Esther, Juan);
    anadirHermano(&b, Juan, Roberto);
    anadirHermano(&b, Juan, Cesar);
    anadirHermano(&b, Juan, Silvia);
    anadirHijo(&b, Roberto, Paloma);
    anadirHijo(&b, Roberto, Blanca);
    anadirHijo(&b, Roberto, Marcos);
    anadirHijo(&b, Silvia, Teresa);
    printf("__%d__", numeroHojas(b));
    printf("%d", numeroNodos(b));
    printf("%d", altura(b));
    TElemento e;
    parent(b, e);
    print(e);
    lista1= crearVacia(&lista1);
    lista2= crearVacia(&lista2);
    lista3= crearVacia(&lista3);
    lista4= crearVacia(&lista4);
    copiar(listaAntepasados(b, Roberto), &lista1); 
    copiar(listaHermanos(b, Juan), &lista2);
    copiar(listaHijos(b, Irene), &lista3);
    copiar(recorrido(b), &lista4);
    mostrar(lista1);
    mostrar(lista2);
    mostrar(lista3);
    mostrar(lista4);

    anadirRaiz(&a, Alfonso);
    lista4= crearVacia(&lista4);
    copiar(recorrido(b), &lista4);
    mostrar(lista4);
    

}