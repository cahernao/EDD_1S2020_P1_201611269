#ifndef NODODOBLE_H
#define NODODOBLE_H
#include <string>
class nodoDoble
{
public:
    nodoDoble(char caracter, int x, int y);
    std::string caracter  ;
    int x;
    int y;
    nodoDoble *next;
    nodoDoble *previous;
};
#endif // NODODOBLE_H
