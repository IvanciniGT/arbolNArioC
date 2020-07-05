#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"



int main(){

    TNTree a=crearArbolVacio(&a);
//    TNTree b=crearArbolVacio(&b);
    //crearArbolVacio(&a);
    //crearArbolVacio(&b);
    TElemento Alfonso = *crear("Alfonso");
    anadirRaiz(&a, Alfonso);
    TNodeNTree* nodo=buscarNodo(a, Alfonso);
    //print(nodo->info);
    TElemento Miguel = *crear("Miguel");
    anadirHijo(&a, Alfonso, Miguel);
    TElemento Lucas = *crear("Lucas");
    anadirHermano(&a, Miguel, Lucas);
    TElemento Gestrudis = *crear("Gertrudis");
    anadirHijo(&a, Miguel, Gestrudis);


/*
    TNodeNTree* nodo2=buscarNodo(a, Miguel);
    print(nodo2->info);
    print(nodo2->padre->info);
    print(nodo2->hermano->info);
    TNodeNTree* nodo3=buscarNodo(a, Lucas);
    print(nodo3->info);
    print(nodo3->padre->info);
    printf("\nNulo: %s\n",nodo3->hermano);
    printf("\nHojas: %i\n",numeroHojas(a));
    printf("\nNodos: %i\n",numeroNodos(a));
    printf("\nAltura: %i\n",altura(a));
    print(*parent(a,Gestrudis));

    TLinkedList lista=listaHijos(a, Alfonso);
    mostrar(lista);



    lista=listaHermanos(a, Miguel);
    mostrar(lista);


    lista=listaHermanos(a, Lucas);
    mostrar(lista);

*/


//    TLinkedList lista = recorrido(a);
//    mostrar(lista);
    borrarNodo(&a,Miguel);
    TLinkedList lista = recorrido(a);

    mostrar(lista);
    /*
 * TElemento Alfonso = *crear("Alfonso");
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

    /*TElemento Pepe, Alfonso, Miguel, Simon, Ana, Jeremias, Alberto, Irene, Gema, Angel, Luis, Felipe, Jesus, Maria, Lucia, Andres, Christian, Daniel, Susana, Pedro, Iker, Patricia, Joel, Laura, Esther, Guadalupe, Emilio, Juan, Roberto, Cesar, Silvia, Paloma, Blanca, Marcos, Teresa;

    Pepe = *crear("Pepe");
    Alfonso = *crear("Alfonso");
    Miguel = *crear("Miguel");
    Simon = *crear("Simon");
    Ana = *crear("Ana");
    Jeremias = *crear("Jeremias");
    Alberto = *crear("Alberto");
    Irene = *crear("Irene");
    Gema = *crear("Gema");
    Angel = *crear("Angel");
    Luis = *crear("Luis");
    Felipe = *crear("Felipe");
    Jesus = *crear("Jesus");
    Maria = *crear("Maria");
    Lucia = *crear("Lucia");
    Andres = *crear("Andres");
    Christian = *crear("Christian");
    Daniel = *crear("Daniel");
    Susana = *crear("Susana");
    Pedro = *crear("Pedro");
    Iker = *crear("Iker");
    Patricia = *crear("Patricia");
    Joel = *crear("Joel");
    Laura = *crear("Laura");
    Esther = *crear("Esther");
    Guadalupe = *crear("Guadalupe");
    Emilio = *crear("Emilio");
    Juan = *crear("Juan");
    Roberto = *crear("Roberto");
    Cesar = *crear("Cesar");
    Silvia = *crear("Silvia");
    Paloma = *crear("Paloma");
    Blanca = *crear("Blanca");
    Marcos = *crear("Marcos");
    Teresa = *crear("Teresa");


    TLinkedList lista1, lista2, lista3, lista4;
/*
    anadirRaiz(&a, Alfonso);
    anadirHijo(&a, Alfonso, Miguel);
    anadirHermano(&a, Miguel, Jeremias);
    anadirHermano(&a, Miguel, Susana);
    anadirHermano(&a, Miguel, Laura);
    anadirHermano(&a, Miguel, Pepe);
    borrarNodo(&a, Pepe);
    copiarArbol(a, &b);
    borrarArbol(&a);
    printf("%d", esArbolVacio(a));
    anadirHijo(&b, Miguel, Simon);
    anadirHijo(&b, Simon, Ana);
    anadirHijo(&b, Jeremias, Alberto);
    anadirHermano(&a, Alberto, Jesus);
    anadirHermano(&a, Alberto, Maria);
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
    printf("%d", numeroHojas(b));
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
    
*/
}