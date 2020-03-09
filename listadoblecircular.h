#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <string>

class Nodo
{
public:
    std::string palabra;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(char letra) {
        this->palabra=letra;
        this->siguiente=NULL;
        this->anterior=NULL;
    }
};
class ListaDobleCircular
{
private:
        Nodo *primero;
        Nodo *ultimo;
        int size;
public:
    ListaDobleCircular();
    void insertar(std::string dato);
    std::string buscar(std::string buscar);
    void graficar();//falta graficar
};

#endif // LISTADOBLECIRCULAR_H
