#include "listadoble.h"
#include <string>
#include <iostream>
#include "string"
#include "iostream"
#include <fstream>
#include <sstream>
#include <time.h>
using namespace  std;

listaDoble::listaDoble(){}

void listaDoble::insertarFinal(char caracter,int x, int y)
{
    nodoDoble * nuevo =new nodoDoble(caracter, x, y);
    if(estaVacia())
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
    return size==0;
}

void listaDoble::imprimir()
{
    nodoDoble *aux=this->first;


    while (aux!=0) {
       cout<<aux->caracter<<"<->";
       aux=aux->next;

    }


}


void listaDoble::graficarLista()
{
    std::string bodyGraph="";
    std::ofstream archivo;
    bodyGraph+="digraph G{\n";
    bodyGraph+="rankdir =LR\n;";
    bodyGraph+="node[shape=box, width=1, height=1];\n";

    nodoDoble *recorrer=this->first;

    if(first->next==0)
    {
        bodyGraph+=recorrer->caracter;
    }else
    {
        while(recorrer->next!=0)
        {
            std::string dato1,dato2;
            std::stringstream c1,c2;
            c1<<recorrer->caracter;
            c1>>dato1;
            c2<<recorrer->next->caracter;
            c2>>dato2;

            bodyGraph+="\""+ dato1+"\n"+to_string(recorrer->x)+","+to_string(recorrer->y)+"\""+"->"+"\""+dato2+"\n"+to_string(recorrer->next->x)+","+to_string(recorrer->next->y)+"\""+"\n";
            bodyGraph+="\""+dato2+"\n"+to_string(recorrer->next->x)+","+to_string(recorrer->next->y)+"\""+"->"+"\""+dato1+"\n"+to_string(recorrer->x)+","+to_string(recorrer->y)+"\""+"\n";
            recorrer=recorrer->next;

        }
    }

    bodyGraph+="}";
    archivo.open("graficaListaD.dot",std::ios::out);
    if(archivo.fail()){
        std::cout<<"No se puede abrir el archivo";
           std::exit(1);
    }
    archivo<<bodyGraph;
    archivo.close();
    std::string salida=("dot graficaListaD.dot -o graficaListaD.png -Tpng");
    const char *comand = salida.c_str();
    system(comand);
    clock_t time_end;
    time_end = clock()+500*CLOCKS_PER_SEC/(float)1000;
    while(clock()<time_end)
    {

    }
    std::string llamar="graficaListaD.png";
    const char *comand2 =llamar.c_str();
    system(comand2);
}


void listaDoble::borrarUltimo()
{
    last=this->last->previous;
    last->next=0;

}




void listaDoble::generarArchivo()
{

    string cuerpo="";
    std::ofstream archivo;

    nodoDoble *reco=this->first;

    while (reco!=0)
    {
        if(reco->caracter=="^")
        {
            cuerpo+="\n";

        }
        else
        {
        cuerpo+=reco->caracter;
        }
       reco=reco->next;
    }

    archivo.open("archivo.txt",std::ios::out);
    if(archivo.fail())
    {
        std::cout<<"No se puede abrir el archivo";
        std::exit(1);
    }
    archivo<<cuerpo;
    archivo.close();
}


void listaDoble::remplazar()
{
   /* nodoDoble *aux = this->first;

    while() {

    }

    */
}

void listaDoble::mostrarCURSES()
{


}


