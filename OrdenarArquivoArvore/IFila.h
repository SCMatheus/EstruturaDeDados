#ifndef IFILA_H
#define IFILA_H
#include <ListaDuplamenteEncadeadaCircular.h>
namespace ED1 {
template <class tipo>
class IFila
{
public:
    virtual void inserir(tipo elemento) = 0;
    virtual tipo remover() = 0;
    virtual tipo acessar() = 0;
    virtual int getQuantidadedeElementos()const = 0;
    virtual bool vazia()const = 0;
};
}
#endif // IFILA_H
