#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *left, *right;
};

struct Arbol{
    Nodo *raiz;
};

void crearArbol(Arbol &arbol){
    arbol.raiz = nullptr;
}

Nodo *crearNodo(int elemento, Nodo *left, Nodo *right){
    Nodo *crearNodo = new struct Nodo;

    crearNodo->dato = elemento;
    crearNodo->left = left;
    crearNodo->right = right;

    return crearNodo;
}

void insertarDatos(Nodo *raiz, int elemento){

    if(raiz == nullptr){
        Nodo *nuevoNodo = crearNodo(elemento, nullptr, nullptr);
        raiz = nuevoNodo;
    }
    else{
        if(raiz->dato > elemento){
            insertarDatos(raiz->left, elemento);
        }
        else{
            insertarDatos(raiz -> right, elemento);
        }
    }
}

void imprimirOrder(Nodo *root){

    if(root != nullptr){
        imprimirOrder(root->left);
        cout<<root->dato;
        imprimirOrder(root->right);
    }
}

int main(){

    Arbol arbol;

    crearArbol(arbol);
    
    insertarDatos(arbol.raiz, 5);
    insertarDatos(arbol.raiz, 2);
    insertarDatos(arbol.raiz, 6);
    insertarDatos(arbol.raiz, 4);
    insertarDatos(arbol.raiz, 3);
    insertarDatos(arbol.raiz, 7);

    imprimirOrder(arbol.raiz);

    return 0;
}