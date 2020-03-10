#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <string>

class NodoCircular
{
public:
    std::string palabra;
    NodoCircular *siguiente;
    NodoCircular *anterior;
    NodoCircular(std::string letra) {
        this->palabra=letra;
        this->siguiente=NULL;
        this->anterior=NULL;
    }
};
class ListaDobleCircular
{
private:
        NodoCircular *primero;
        NodoCircular *ultimo;
        int size;
public:
    ListaDobleCircular();
    void insertar(std::string dato);
    std::string buscar(std::string buscar);
    std::string toString();
    void graficar();//falta graficar
};

#endif // LISTADOBLECIRCULAR_H
