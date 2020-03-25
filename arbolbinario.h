#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <stdio.h>
#include "cola.h"
#include "listasimpleordenada.h"
#include "listadoble.h"

class NodoArbol
{
public:
    std::string dato;
    NodoArbol *izq,*der;
    ListaSimpleOrdenada *punteo;
    ListaDoble *fichas;
    NodoArbol(std::string data) {
        this->dato=data;
        this->izq=NULL;
        this->der=NULL;
        this->punteo=new ListaSimpleOrdenada();
        this->fichas=new ListaDoble();
    }
};
class ArbolBinario
{
private:
    bool privadoInsertar(std::string data,NodoArbol *&raiz);
    void privadoRemover(std::string data,NodoArbol *&raiz);
    void privadoPreorder(NodoArbol *raiz,Cola *aux);
    void privadoInorder(NodoArbol *raiz,Cola *aux);
    void privadoPostorder(NodoArbol *raiz,Cola *aux);
    NodoArbol *findMin(NodoArbol *raiz);
    NodoArbol *getPrivdo(NodoArbol *raiz, std::string nombre);
    void imprimir(NodoArbol *tree,FILE *stream);
    void auximprimir(NodoArbol *tree,FILE *stream);
    void marcarNUL(std::string key, int nullcount, FILE* stream);
public:
    NodoArbol *root;
    ArbolBinario();
    bool insertar(std::string data);
    NodoArbol *get(std::string nombre);
    void remover(std::string data);
    void preorder();
    void inorder();
    void postorder();
    void graficar();
};

#endif // ARBOLBINARIO_H
