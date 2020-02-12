#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <iostream>
#include <string.h>
#include <fstream>

#include <time.h>


using namespace std;


class algoritmos
{
    public:
        algoritmos() {}

        void leerArchivo();
        string leerArchivoString();
        ifstream nombreAc();

        void dormir(int milis);




};

void algoritmos::dormir(int milis)
{
    clock_t time_end;
    time_end = clock()+milis*CLOCKS_PER_SEC/(float)1000;
    while(clock()<time_end)
    {

    }
}

void algoritmos::leerArchivo()
{
    string nombre, linea;
    cout<<"Ingrese nombre archivo: "<<endl;
    cin>>nombre;
    ifstream myFile;

    myFile.open("C:\\Users\\CX\\Desktop\\"+nombre, ios::out);
    if(myFile.is_open())
    {
        while(getline(myFile, linea))
        {
            cout<<linea<<endl;
        }
    }else
    {
        cout<<"Error abriendo el archivo"<<endl;
    }
    myFile.close();

}

ifstream algoritmos::nombreAc()
{

    string nombre, linea;
    cout<<"Ingrese nombre archivo: "<<endl;
    cin>>nombre;
    ifstream myFile(nombre);

}

string algoritmos::leerArchivoString()
{
    string nombre, linea, valor="", nValor;
    try
    {
        cout<<"Ingrese nombre archivo: "<<endl;
        cin>>nombre;
        ifstream myFile;

        myFile.open("C:\\Users\\CX\\Desktop\\"+nombre, ios::in);
        if(myFile.is_open())
        {
            while(getline(myFile, linea))
            {
                valor+=linea+'\n';
            }
        }else
        {
            cout<<"Error abriendo el archivo"<<endl;
        }
        myFile.close();
    }
    catch (const exception& e)
    {
        cout<<"Error en el archivo "<<e.what()<<'\n';
        return 0;

    }
    return valor;
}


#endif // ALGORITMOS_H
