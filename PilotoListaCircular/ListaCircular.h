#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include<No.h>
#include<QString>

namespace ED1{
class Lista
{
private:
    int quantidadeDeElementos;
    No* inicio;
    No* fim;
public:
    Lista():quantidadeDeElementos(0),inicio(0){}
    ~Lista();//implemetar apagar a lista
    bool listaVazia()const{return quantidadeDeElementos==0;}
    int getQuantidadeDeElementos()const{return quantidadeDeElementos;}
    void inserirInicio(Piloto elemento);
    Piloto retirarInicio();
    void inserirFim(Piloto elemento);
    Piloto retirarFim();
    void inserirNoMeio(Piloto elemento, int posicao);
    Piloto operator[] (int posicao);
    Piloto retirarDoMeio(int posicao);
    void inserirOrdenado(Piloto elemento);
    Piloto retirarElemento(Piloto elemento);
    Piloto acessarElemento(Piloto elemento);
};
}

#endif // LISTACIRCULAR_H
