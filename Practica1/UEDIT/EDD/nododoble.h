#ifndef NODODOBLE_H
#define NODODOBLE_H
#include <string>

class nodoDoble
{
public:
    nodoDoble(std::string caracter);
    std::string caracter;
    nodoDoble *next;
    nodoDoble *previous;
};

#endif // NODODOBLE_H
