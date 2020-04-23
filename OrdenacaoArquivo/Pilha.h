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
    tipo acessar()const{return lista[((lista.getQuantidadeDeElementos() - 1))];}
    int getQuantidadedeElementos()const{return lista.getQuantidadeDeElementos();}
    bool vazia()const{return lista.listaVazia();}
};
}
#endif // PILHA_H
