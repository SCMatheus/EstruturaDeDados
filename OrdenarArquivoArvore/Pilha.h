#ifndef PILHA_H
#define PILHA_H
#include <IPilha.h>


namespace ED1 {
template <class tipo>
class Pilha : public IPilha<tipo>
{
private:
    ListaDuplamenteEncadeadaCircular<tipo> lista;
public:
    Pilha(){}
    void inserir(tipo elemento){lista.inserirFim(elemento);}
    tipo remover(){return lista.retirarFim();}
    tipo acessar(){return lista[(lista.getQuantidadeDeElementos()) - 1];}
    int getQuantidadedeElementos(){return lista.getQuantidadeDeElementos();}
    bool vazia(){return lista.listaVazia();}
};
}
#endif // PILHA_H
