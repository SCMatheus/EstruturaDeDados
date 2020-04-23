#ifndef IPILHA_H
#define IPILHA_H

namespace ED1{

template <class tipo>
class IPilha
{
public:
    virtual void inserir(tipo elemento) = 0;
    virtual tipo remover() = 0;
    virtual tipo acessar() = 0;
    virtual int getQuantidadedeElementos() = 0;
    virtual bool vazia() = 0;
};
}
#endif // IPILHA_H
