#include "listadoble.h"
#include <string>
#include <iostream>
using namespace  std;

listaDoble::listaDoble()
{
root=nullptr;
first=nullptr;
last=nullptr;

}

void listaDoble::insertarFinal(std::string caracter)
{

    nodoDoble * nuevo =new nodoDoble(caracter);
    if(estaVacia()==true)
    {
        first=nuevo;
        last=nuevo;
        size++;
    }
    else
    {
        last->next=nuevo;
        nuevo->previous=last;
        last=nuevo;
       size++;
    }


}

bool listaDoble::estaVacia()
{
    if(first==nullptr)
    {
        return
                 true;
    }else
    {
        return  false;
    }

}

void listaDoble::imprimir()
{
    nodoDoble *aux=this->first;


    while (aux!=nullptr) {
       cout<<aux->caracter<<"<->";
       aux=aux->next;

    }


}
