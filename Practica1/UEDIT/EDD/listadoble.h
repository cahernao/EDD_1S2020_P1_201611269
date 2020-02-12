#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "EDD/nododoble.h"

class listaDoble
{
public:
    listaDoble();
    nodoDoble *root;
    nodoDoble *first;
    nodoDoble *last;

    int size=0;

    void insertarFinal(std::string caracter);
    bool estaVacia();
    void graficar();
    void imprimir();

};

#endif // LISTADOBLE_H
