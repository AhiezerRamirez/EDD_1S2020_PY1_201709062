#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>

class NodoArbol
{
public:
    int dato;
    NodoArbol *izq,*der;
    NodoArbol(int data) {
        this->dato=data;
        this->izq=NULL;
        this->der=NULL;
    }
};
class ArbolBinario
{
private:
    void privadoInsertar(int data,NodoArbol *&raiz);
    void privadoRemover(int data,NodoArbol *&raiz);
    void privadoInorder(NodoArbol *raiz);
    NodoArbol *findMin(NodoArbol *raiz);
public:
    NodoArbol *root;
    ArbolBinario();
    void insertar(int data);
    void remover(int data);
    void inorder();
};

#endif // ARBOLBINARIO_H
