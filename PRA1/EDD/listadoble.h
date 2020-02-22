#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "nododoble.h"

using namespace std;

class listaDoble
{

public:
    listaDoble();
    nodoDoble *root;
    nodoDoble *first;
    nodoDoble *last;
    int size=0;
    void insertarFinal(char caracter, int x, int y);
    bool estaVacia();
    void graficar();
    void imprimir();
    void borrarUltimo();
    void generarArchivo();
    void modificar();
    void graficarLista();
    void remplazar();
    void mostrarCURSES();

};

#endif // LISTADOBLE_H
