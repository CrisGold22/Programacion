#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *left;
    Nodo *rigth;
};

struct Arbol{
    Nodo *raiz;
};

void crearArbol(Arbol &arbol){
    arbol.raiz = nullptr;
}

bool esNodoVacio(Nodo *raiz){
    return raiz == nullptr;
}

bool esArbolVacio(const Arbol &arbol){
    return esNodoVacio(arbol.raiz);
}

Nodo *crearNodo(Nodo *left, Nodo *right, int elemento){

    Nodo *nodo = new struct Nodo;

    nodo->dato = elemento;
    nodo->left = left;
    nodo->rigth = right;

    return nodo;
    
}

void plantarArbolBinario1(Arbol &arbol, Nodo *left, Nodo *right, int elemento){

    Nodo *nuevoNodo = crearNodo(left, left, elemento);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario2(Arbol &arbol, Arbol &left, Arbol &right, int elemento){

    Nodo *nuevoNodo = crearNodo(left.raiz, right.raiz, elemento);
    arbol.raiz = nuevoNodo;
}

void imprimirNodo(Nodo *nodo){
    cout<<setw(5)<<nodo->dato<<endl;
}

void imprimir(const Arbol &arbol){
    imprimirNodo(arbol.raiz);
}

void recursivoPreOrden(Nodo *nodo){

    if(not esNodoVacio(nodo)){
        imprimirNodo(nodo);
        recursivoPreOrden(nodo->left);
        recursivoPreOrden(nodo->rigth);
    }

}

void recorrerPreOrden(const Arbol &arbol){
    recursivoPreOrden(arbol.raiz);
}

void recursivoInOrden(Nodo *nodo){

    if(not esNodoVacio(nodo)){
        recursivoInOrden(nodo->left);
        imprimirNodo(nodo);
        recursivoInOrden(nodo->rigth);
    }

}

void recorrerInOrden(const Arbol &arbol){
    recursivoInOrden(arbol.raiz);
}

void recursivoPosOrden(Nodo *nodo){

    if(not esNodoVacio(nodo)){
        recursivoPosOrden(nodo->left);
        recursivoPosOrden(nodo->rigth);
        imprimirNodo(nodo);
    }

}

void recorrerPosOrden(const Arbol &arbol){
    recursivoPosOrden(arbol.raiz);
}


int main(){

    Arbol arbol; 
    crearArbol(arbol);

    plantarArbolBinario1(arbol, nullptr, nullptr, 100);
    Arbol arbol1, arbol2, arbol3, arbol4;
    plantarArbolBinario1(arbol1, nullptr, nullptr, 150);
    plantarArbolBinario1(arbol2, nullptr, nullptr, 120);
    plantarArbolBinario2(arbol3, arbol1, arbol2, 50);
    plantarArbolBinario1(arbol4, nullptr, nullptr, 100);
    plantarArbolBinario2(arbol, arbol3, arbol4, 50);

    imprimir(arbol);

    recorrerPreOrden(arbol);

    return 0;
}