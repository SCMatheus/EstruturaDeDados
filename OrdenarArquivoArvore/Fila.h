#ifndef FILA_H
#define FILA_H
#include <IFila.h>
namespace ED1 {
template <class tipo>
class Fila : public IFila<tipo>
{
private:
    ListaDuplamenteEncadeadaCircular<tipo> lista;
public:
    Fila(){}
    void inserir(tipo elemento){lista.inserirFim(elemento);}
    tipo remover(){return lista.retirarInicio();}
    tipo acessar(){return lista[0];}
    int getQuantidadedeElementos()const{return lista.getQuantidadeDeElementos();}
    bool vazia()const{return lista.listaVazia();}
};
}
#endif // FILA_H
