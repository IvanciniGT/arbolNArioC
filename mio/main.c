#include <stdio.h>
#include "NTree.h"
#include "simplelinkedlist.h"

int main(){
    TNTree a;
    TNTree b;
    crearArbolVacio(&a);
    crearArbolVacio(&b);
    anadirRaiz(&a, *crear("Alfonso")) ;
    anadirHijo(&a, *crear("Alfonso") , *crear("Miguel")) ;
    anadirHermano(&a, *crear("Miguel") , *crear("Jeremias")) ;
    anadirHermano(&a, *crear("Miguel") , *crear("Susana")) ;
    anadirHermano(&a, *crear("Miguel") , *crear("Laura")) ;
    anadirHermano(&a, *crear("Miguel") , *crear("Pepe")) ;
    borrarNodo(&a, *crear("Pepe")) ;
    copiarArbol(a, &b);
    borrarArbol(&a);
    printf("%d" , esArbolVacio(a));
    anadirHijo(&b, *crear("Miguel") , *crear("Simon")) ;
    anadirHijo(&b, *crear("Simon") , *crear("Ana")) ;
    anadirHijo(&b, *crear("Jeremias") , *crear("Alberto")) ;
    anadirHermano(&a, *crear("Alberto") , *crear("Jesus")) ;
    anadirHermano(&a, *crear("Alberto") , *crear("Maria")) ;
    anadirHijo(&b, *crear("Alberto") , *crear("Irene")) ;
    anadirHijo(&b, *crear("Alberto") , *crear("Felipe")) ;
    anadirHijo(&b, *crear("Irene") , *crear("Gema")) ;
    anadirHijo(&b, *crear("Irene") , *crear("Angel")) ;
    anadirHijo(&b, *crear("Irene") , *crear("Luis")) ;
    anadirHijo(&b, *crear("Maria") , *crear("Lucia")) ;
    anadirHijo(&b, *crear("Maria") , *crear("Andres")) ;
    anadirHijo(&b, *crear("Andres") , *crear("Christian")) ;
    anadirHijo(&b, *crear("Andres") , *crear("Daniel")) ;
    anadirHijo(&b, *crear("Susana") , *crear("Pedro")) ;
    anadirHermano(&b, *crear("Pedro") , *crear("Iker")) ;
    anadirHijo(&b, *crear("Pedro") , *crear("Patricia")) ;
    anadirHijo(&b, *crear("Patricia") , *crear("Joel")) ;
    anadirHijo(&b, *crear("Laura") , *crear("Esther")) ;
    anadirHermano(&b, *crear("Esther") , *crear("Guadalupe")) ;
    anadirHermano(&b, *crear("Guadalupe") , *crear("Emilio")) ;
    anadirHijo(&b, *crear("Esther") , *crear("Juan")) ;
    anadirHermano(&b, *crear("Juan") , *crear("Roberto")) ;
    anadirHermano(&b, *crear("Juan") , *crear("Cesar")) ;
    anadirHermano(&b, *crear("Juan") , *crear("Silvia")) ;
    anadirHijo(&b, *crear("Roberto") , *crear("Paloma")) ;
    anadirHijo(&b, *crear("Roberto") , *crear("Blanca")) ;
    anadirHijo(&b, *crear("Roberto") , *crear("Marcos")) ;
    anadirHijo(&b, *crear("Silvia") , *crear("Teresa")) ;
    printf("%d" , numeroHojas(b));
    printf("%d" , numeroNodos(b));
    printf("%d" , altura(b));
    TElemento e;
    padre(b, e);
    print(e);
//    mostrar(listaAntepasados(b));
//    mostrar(listaHermanos(b));
//    mostrar(listaHijos(b));
//    mostrar(recorrido(b));
}