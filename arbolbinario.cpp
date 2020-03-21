#include "arbolbinario.h"
#include <chrono>
#include <thread>
#include <fstream>

ArbolBinario::ArbolBinario()
{
    this->root=NULL;
}

void ArbolBinario::insertar(std::string data){
    privadoInsertar(data,this->root);
}

void ArbolBinario::privadoInsertar(std::string data, NodoArbol *&raiz){
    if(raiz == NULL)
    raiz= new NodoArbol(data);
    else if (data.compare(raiz->dato) < 0) {
        if(raiz->izq !=NULL)
            privadoInsertar(data,raiz->izq);
        else
            raiz->izq=new NodoArbol(data);

    }else if(data.compare(raiz->dato) > 0){
        if(raiz->der !=NULL)
            privadoInsertar(data,raiz->der);
        else
            raiz->der=new NodoArbol(data);
    }else {
        std::cout<<"El usuario ya existe"<<std::endl;
    }

}

void ArbolBinario::remover(std::string data){
    privadoRemover(data,this->root);
}

NodoArbol *ArbolBinario::findMin(NodoArbol *raiz){
    while (raiz->izq!=NULL) {
        raiz=raiz->izq;
    }
    return raiz;
}

void ArbolBinario::privadoRemover(std::string data, NodoArbol *&raiz){
    if(raiz==NULL)
        return;
    else if(data < raiz->dato)
        privadoRemover(data,raiz->izq);
    else if(data > raiz->dato)
        privadoRemover(data,raiz->der);
    else{
        if(raiz->izq==NULL && raiz->der==NULL){
            delete raiz;
            //raiz==NULL;
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

void ArbolBinario::preorder(){
    Cola *aux=new Cola();
    privadoPreorder(this->root,aux);
    std::string cadena="digraph G {\n node [shape = square]; \n graph [rankdir=LR];\n";
    while (aux->primero->siguiente!=NULL) {
        cadena+=aux->desencolar()->letra+" -> ";
    }
    cadena+=aux->desencolar()->letra+" \n}";
    std::string ruta;
        ruta="/home/ahiezer/Proyecto1Edd2020/preorder.dot";
        std::ofstream fileCitas;
        fileCitas.open(ruta.c_str());
        fileCitas<<cadena;
        fileCitas.close();
        system("cd /home/ahiezer/Proyecto1Edd2020/ && dot preorder.dot -Tjpg -o preorder.jpg");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("xdg-open /home/ahiezer/Proyecto1Edd2020/preorder.jpg");
}

void ArbolBinario::privadoPreorder(NodoArbol *raiz,Cola *aux){
    if(raiz==NULL){
        return;
    }
    //std::cout<<raiz->dato+" ->";
    aux->encolar(raiz->dato,1);
    //fprintf(stream, "    %s -> ", raiz->dato);
    privadoPreorder(raiz->izq,aux);
    privadoPreorder(raiz->der,aux);
}

void ArbolBinario::inorder(){
    Cola *aux=new Cola();
    privadoInorder(this->root,aux);
    std::string cadena="digraph G {\n node [shape = square]; \n graph [rankdir=LR];\n";
    while (aux->primero->siguiente!=NULL) {
        cadena+=aux->desencolar()->letra+" -> ";
    }
    cadena+=aux->desencolar()->letra+" \n }";

    std::string ruta;
        ruta="/home/ahiezer/Proyecto1Edd2020/inorder.dot";
        std::ofstream fileCitas;
        fileCitas.open(ruta.c_str());
        fileCitas<<cadena;
        fileCitas.close();
        system("cd /home/ahiezer/Proyecto1Edd2020/ && dot inorder.dot -Tjpg -o inorder.jpg");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("xdg-open /home/ahiezer/Proyecto1Edd2020/inorder.jpg");
}

void ArbolBinario::privadoInorder(NodoArbol *raiz,Cola *aux){
    if(raiz==NULL){
        return;
    }
    privadoInorder(raiz->izq,aux);
    aux->encolar(raiz->dato,1);
    privadoInorder(raiz->der,aux);
}

void ArbolBinario::postorder(){
    Cola *aux=new Cola();
    privadoPostorder(this->root,aux);
    std::string cadena="digraph G {\n node [shape = square]; \n graph [rankdir=LR];\n";
    while (aux->primero->siguiente!=NULL) {
        cadena+=aux->desencolar()->letra+" -> ";
    }
    cadena+=aux->desencolar()->letra+" \n}";
    std::string ruta;
        ruta="/home/ahiezer/Proyecto1Edd2020/postorder.dot";
        std::ofstream fileCitas;
        fileCitas.open(ruta.c_str());
        fileCitas<<cadena;
        fileCitas.close();
        system("cd /home/ahiezer/Proyecto1Edd2020/ && dot postorder.dot -Tjpg -o postorder.jpg");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("xdg-open /home/ahiezer/Proyecto1Edd2020/postorder.jpg");
}

void ArbolBinario::privadoPostorder(NodoArbol *raiz,Cola *aux){
    if(raiz==NULL){
        return;
    }
    privadoPostorder(raiz->izq,aux);
    privadoPostorder(raiz->der,aux);
    aux->encolar(raiz->dato,1);
}

void ArbolBinario::marcarNUL(std::string key, int nullcount, FILE *stream){
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %s -> null%s;\n", key, nullcount);
}

void ArbolBinario::auximprimir(NodoArbol *node, FILE *stream){
    static int nullcount = 0;

        if (node->izq)
        {
            fprintf(stream, "    %s -> %s;\n", node->dato.c_str(), node->izq->dato.c_str());
            auximprimir(node->izq, stream);
        }
        //else
            //marcarNUL(node->dato, nullcount++, stream);

        if (node->der)
        {
            fprintf(stream, "    %s -> %s;\n", node->dato.c_str(), node->der->dato.c_str());
            auximprimir(node->der, stream);
        }
        //else
            //marcarNUL(node->dato, nullcount++, stream);
}

void ArbolBinario::imprimir(NodoArbol *tree,FILE *stream){
    fprintf(stream, "digraph BST {\n");
        fprintf(stream, "    node [fontname=\"Arial\"];\n");

        if (!tree)
            fprintf(stream, "\n");
        else if (!tree->der && !tree->izq)
            fprintf(stream, "    %s;\n", tree->dato.c_str());
        else
            auximprimir(tree, stream);

        fprintf(stream, "}\n");
}
void ArbolBinario::graficar(){
    FILE *archivo;
    archivo=fopen("/home/ahiezer/Proyecto1Edd2020/arbol.dot","w");
    imprimir(this->root,archivo);
    fclose(archivo);
    system("cd /home/ahiezer/Proyecto1Edd2020/ && dot arbol.dot -Tjpg -o arbol.jpg");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("xdg-open /home/ahiezer/Proyecto1Edd2020/arbol.jpg");
}
