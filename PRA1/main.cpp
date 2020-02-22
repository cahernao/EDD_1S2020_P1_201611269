#include <iostream>
#include "curses.h"
#include "Objetos/pantallas.h"
#include "EDD/listadoble.h"
#include "EDD/nododoble.h"
using namespace std;

void curses();
void arcRec();
static void finish(int sig);

void curses()
{
    try{

        listaDoble *miLista = new listaDoble();
        pantallas* miPantalla = new pantallas();

        char msg1[]="F12 Salir";
        char msg2[]="F2 ByR";
        char msg3[]="F3 Reportes";
        char msg4[]="F4 Guardar";
        int row, col;
        int ch;

        int x=0;
        int y=0;
        int xborar=-10;
        int yborrar=-10;
        initscr(); //inicializando curses

        getmaxyx(stdscr,row,col);
        raw(); //linea de bufer desabilitada
        keypad(stdscr,TRUE); // We get F1,F2 etc

        noecho();
        nonl();
        cbreak();
        mvprintw(row/2,0,msg1);
        mvprintw(row/2,12,msg2);
        mvprintw(row/2,24,msg3);
        mvprintw(row/2,37,msg4);
        move(x,y);

        while((ch=getch())!=KEY_F(12))
        {
                switch(ch){
                case KEY_LEFT:
                    move(x,--y);
                    break;
                case KEY_BACKSPACE:

                    move(x,--y);
                    break;
                case 13:
                    y=0;
                    miLista->insertarFinal('.',xborar,yborrar);
                    --xborar;
                    --yborrar;
                    move(++x,y);
                    break;

                case KEY_F(3):
                    //miPantalla->reemplazar();
                    miLista->graficarLista();
                    break;

                 default:

                    ++y;
                    miLista->insertarFinal(ch, y, x);
                    printw("%c", ch);

                    break;
                }
        }//FIN WHILE
        clear();
        refresh();
        printw(" presione otra tecla para salir");
        getch();
        clear();
        endwin();
        delete miPantalla;
    } catch(char* ex){
        endwin();
        cout<<ex;
    }
}

void cursesAbrir(string cadena)
{
    try{

        listaDoble *miLista = new listaDoble();
        pantallas* miPantalla = new pantallas();

        char msg1[]="F12 Salir";
        char msg2[]="F2 ByR";
        char msg3[]="F3 Reportes";
        char msg4[]="F4 Guardar";
        int row, col;
        int ch;

        int x=0;
        int y=0;
        int xborar=-10;
        int yborrar=-10;
        initscr(); //inicializando curses

        getmaxyx(stdscr,row,col);
        raw(); //linea de bufer desabilitada
        keypad(stdscr,TRUE); // We get F1,F2 etc

        noecho();
        nonl();
        cbreak();
        mvprintw(row/2,0,msg1);
        mvprintw(row/2,12,msg2);
        mvprintw(row/2,24,msg3);
        mvprintw(row/2,37,msg4);
        move(x,y);

        char h;
        for(int a=0;a<cadena.length();a++){
            h=cadena.at(a);
            if(h=='\n'){
                x++;
                miLista->insertarFinal(h, x, y);
            }else{
                y++;
                miLista->insertarFinal(h, x, y);
            }
            printw("%c", h);

        }

        while((ch=getch())!=KEY_F(12))
        {
                switch(ch){
                case KEY_LEFT:
                    move(x,--y);
                    break;
                case KEY_BACKSPACE:

                    move(x,--y);
                    break;
                case 13:
                    y=0;
                    miLista->insertarFinal('.',xborar,yborrar);
                    --xborar;
                    --yborrar;
                    move(++x,y);
                    break;

                case KEY_F(3):
                    //miPantalla->reemplazar();
                    miLista->graficarLista();
                    break;

                 default:

                    ++y;
                    miLista->insertarFinal(ch, y, x);
                    printw("%c", ch);

                    break;
                }
        }//FIN WHILE
        clear();
        refresh();
        printw(" presione otra tecla para salir");
        getch();
        clear();
        endwin();
        delete miPantalla;
    } catch(char* ex){
        endwin();
        cout<<ex;
    }
}

static void finish(int sig)
{
    endwin();
    exit(0);
}

int main()
{
    pantallas* miPant =new pantallas();


    int opcion;
    do{

        cout<<" UNIVERSIDAD DE SAN CARLOS "<<std::endl;
        cout<<" FACULTAD DE INGENIERIA " <<std::endl;
        cout<<" ESTRUCTURA DE DATOS "<<std::endl;
        cout<<" PRACTICA 1 "<<std::endl;
        cout<<" CARLOS AUGUSTO HERNÁNDEZ "<<std::endl;
        cout<<" 201611269 "<<std::endl;
        cout<<"    MENU "<<std::endl;
        cout<<"     1. Crear archivo"<<endl;
        cout<<"     2. Abrir Archivo"<<endl;
        cout<<"     3. Archivos Recientes"<<endl;
        cout<<"     4. salir"<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            curses();
            break;
        case 2:
            cursesAbrir(miPant->leerArchivoString());
            break;
        case 3:
            arcRec();
            break;

        }

   }while (opcion !=4);

    return 0;
}




void arcRec()
{
    initscr();
    refresh();
    printw("\n\nPerro presionaste recientes\n\n");
    getch();
    endwin();

}
