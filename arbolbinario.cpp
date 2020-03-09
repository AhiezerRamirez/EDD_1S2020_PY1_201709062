#include "arbolbinario.h"

ArbolBinario::ArbolBinario()
{
    this->root=NULL;
}

void ArbolBinario::insertar(int data){
    privadoInsertar(data,this->root);
}

void ArbolBinario::privadoInsertar(int data, NodoArbol *&raiz){
    if(raiz == NULL)
    raiz= new NodoArbol(data);
    else if (data < raiz->dato) {
        if(raiz->izq !=NULL)
            privadoInsertar(data,raiz->izq);
        else
            raiz->izq=new NodoArbol(data);

    }else if(data > raiz->dato){
        if(raiz->der !=NULL)
            privadoInsertar(data,raiz->der);
        else
            raiz->der=new NodoArbol(data);
    }
    //return raiz;
}

void ArbolBinario::remover(int data){
    privadoRemover(data,this->root);
}

NodoArbol *ArbolBinario::findMin(NodoArbol *raiz){
    while (raiz->izq!=NULL) {
        raiz=raiz->izq;
    }
    return raiz;
}

void ArbolBinario::privadoRemover(int data, NodoArbol *&raiz){
    if(raiz==NULL)
        return;
    else if(data < raiz->dato)
        privadoRemover(data,raiz->izq);
    else if(data > raiz->dato)
        privadoRemover(data,raiz->der);
    else{
        if(raiz->izq==NULL && raiz->der==NULL){
            delete raiz;
            raiz==NULL;
        }else if (raiz->izq ==NULL) {
            NodoArbol *temp=raiz;
            raiz=raiz->der;
            delete temp;
        }else if(raiz->der == NULL){
            NodoArbol *temp=raiz;
            raiz=raiz->izq;
            delete temp;
        }else{
            NodoArbol *temp=findMin(raiz->der);
            raiz->dato=temp->dato;
            privadoRemover(temp->dato,raiz->der);
        }
    }
}

void ArbolBinario::inorder(){
    privadoInorder(this->root);
}

void ArbolBinario::privadoInorder(NodoArbol *raiz){
    if(raiz==NULL)
        return;
    privadoInorder(raiz->izq);
    std::cout<<std::to_string(raiz->dato)+", ";
    privadoInorder(raiz->der);
}
