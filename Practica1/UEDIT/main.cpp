#include <iostream>
#include <EDD/listadoble.h>
#include <ALGORITMO/algoritmos.h>
using namespace std;

int main()
{
    algoritmos algoritmo;
    string dato;
    int opcion;
    string nodoBuscado;


        do{

            std::cout<<"        UNIVERSIDAD DE SAN CARLOS DE GUATEMALA"<<std::endl;
            std::cout<<"        FACULTAD DE INGENIERIA"<<std::endl;
            std::cout<<"        ESTRUCTURA DE DATOS"<<std::endl;
            std::cout<<"        PRACTICA 1"<<std::endl;
            std::cout<<"        CARLOS AUGUSTO HERNANDEZ"<<std::endl;
            std::cout<<"        201611269"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"        Menu"<<std::endl;
            std::cout<<"        1.Crear Archivo"<<std::endl;
            std::cout<<"        2.Abrir Archivo"<<std::endl;
            std::cout<<"        3.Archivos recientes"<<std::endl;
            std::cout<<"        4.Salir"<<std::endl;
            std::cin>>opcion;

            switch (   opcion )
            {
            case 1:
                cout<<"AQUI DEBEMOS HACER ALGO :v";
                break;

            case 2:
                string contenido = algoritmo.leerArchivoString();
                cout<<contenido<<endl;
                break;

        }
        }while(opcion!=4);



    return 0;
}
