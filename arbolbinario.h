#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <stdio.h>
#include "cola.h"

class NodoArbol
{
public:
    std::string dato;
    NodoArbol *izq,*der;
    NodoArbol(std::string data) {
        this->dato=data;
        this->izq=NULL;
        this->der=NULL;
    }
};
class ArbolBinario
{
private:
    void privadoInsertar(std::string data,NodoArbol *&raiz);
    void privadoRemover(std::string data,NodoArbol *&raiz);
    void privadoPreorder(NodoArbol *raiz,Cola *aux);
    void privadoInorder(NodoArbol *raiz,Cola *aux);
    void privadoPostorder(NodoArbol *raiz,Cola *aux);
    NodoArbol *findMin(NodoArbol *raiz);

    void imprimir(NodoArbol *tree,FILE *stream);
    void auximprimir(NodoArbol *tree,FILE *stream);
    void marcarNUL(std::string key, int nullcount, FILE* stream);
public:
    NodoArbol *root;
    ArbolBinario();
    void insertar(std::string data);
    void remover(std::string data);
    void preorder();
    void inorder();
    void postorder();
    void graficar();
};

#endif // ARBOLBINARIO_H
