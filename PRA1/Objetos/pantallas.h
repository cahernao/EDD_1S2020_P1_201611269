#ifndef PANTALLAS_H
#define PANTALLAS_H
#include <curses.h>
#include <string.h>
#include <fstream>


using namespace std;
class pantallas
{
    public:

        pantallas(){
            vieja="";
            nueva="";
        }


        //virtual ~pantallas() {}
        string vieja, nueva;
        string leerArchivoString();

        void reemplazar();
};

void pantallas::reemplazar(){

    char mensaje[]="Escriba la palabra";
    int row, col;
    int ch;
    int x=0;
    int y=0;
    int xborar=-10;
    int yborrar=-10;

    getmaxyx(stdscr,row,col);
    raw(); //linea de bufer desabilitada
    keypad(stdscr,TRUE); // We get F1,F2 etc

    noecho();
    nonl();
    cbreak();
    mvprintw(0,0,mensaje);
    move(x+1,y);
    /*while((ch=getch())!=KEY_ENTER)
    {


    }*/


}

string pantallas::leerArchivoString()
{
    string nombre, linea, valor="", nValor;
    try
    {
        cout<<"Ingrese nombre archivo: "<<endl;
        cin>>nombre;
        ifstream myFile;

        myFile.open(nombre, ios::out);
        if(myFile.is_open())
        {
            while(getline(myFile, linea))
            {
                valor+=linea;
            }
        }else
        {
            cout<<"Error abriendo el archivo"<<endl;
        }
        myFile.close();
    }
    catch (const exception& e)
    {
        cout<<"Error en el archivo "<<endl;
        return 0;

    }
    return valor;
}

#endif // PANTALLAS_H
