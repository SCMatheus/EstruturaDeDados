#ifndef IPILHA_H
#define IPILHA_H
#include <ListaDuplamenteEncadeadaCircular.h>

namespace ED1{

template <class tipo>
class IPilha
{
public:
    virtual void inserir(tipo elemento) = 0;
    virtual tipo remover() = 0;
    virtual tipo acessar()const = 0;
    virtual int getQuantidadedeElementos()const = 0;
    virtual bool vazia()const = 0;
};
}
#endif // IPILHA_H
