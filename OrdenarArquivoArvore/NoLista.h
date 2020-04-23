#ifndef NOLISTA_H
#define NOLISTA_H

namespace ED1{
template <class tipo>
class NoLista
{
private:
    tipo informacao;
    NoLista<tipo> *proximo;
    NoLista<tipo> *anterior;
public:
    NoLista():proximo(0),anterior(0){}
    NoLista(tipo informacao):informacao(informacao),proximo(0),anterior(0){}
    ~NoLista(){proximo=0;}
    tipo getInformacao()const{return informacao;}
    void setInformacao(tipo informacao){this->informacao=informacao;}
    NoLista<tipo>* getProximo()const{return proximo;}
    void setProximo(NoLista<tipo>* proximo){this->proximo = proximo;}
    NoLista<tipo>* getAnterior()const{return anterior;}
    void setAnterior(NoLista<tipo>* anterior){this->anterior = anterior;}

};
}
#endif // NOLISTA_H
