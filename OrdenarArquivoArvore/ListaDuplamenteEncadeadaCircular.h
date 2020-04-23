#ifndef LISTADUPLAMENTEENCADEADACIRCULAR_H
#define LISTADUPLAMENTEENCADEADACIRCULAR_H
#include<NoLista.h>
#include<QString>
namespace ED1 {
template <class tipo>
class ListaDuplamenteEncadeadaCircular
{
private:
    int quantidadeDeElementos;
    NoLista<tipo> *inicio;
    NoLista<tipo> *fim;
public:
    ListaDuplamenteEncadeadaCircular():quantidadeDeElementos(0),inicio(0){}
    ~ListaDuplamenteEncadeadaCircular();
    bool listaVazia()const{return quantidadeDeElementos==0;}
    int getQuantidadeDeElementos()const{return quantidadeDeElementos;}
    void inserirInicio(tipo elemento);
    tipo retirarInicio();
    void inserirFim(tipo elemento);
    tipo retirarFim();
    void inserirNoMeio(tipo elemento, int posicao);
    tipo operator[] (int posicao);
    tipo retirarDoMeio(int posicao);
    void inserirOrdenado(tipo elemento);
    tipo retirarElemento(tipo elemento);
    tipo acessarElemento(tipo elemento);
};

template<class tipo>
void ListaDuplamenteEncadeadaCircular<tipo>::inserirInicio(tipo elemento){
    NoLista<tipo> *pt = 0;
    try {
        pt = new NoLista<tipo>(elemento);
    } catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
    if(quantidadeDeElementos == 0){
        pt->setProximo(pt);
        pt->setAnterior(pt);
        inicio = fim = pt;
        quantidadeDeElementos++;
        return;
    }
    pt->setProximo(inicio);
    inicio->setAnterior(pt);
    inicio = pt;
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    quantidadeDeElementos++;
    return;
}
template<class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::retirarInicio(){
    if(listaVazia()) throw QString("Lista Vazia");
    NoLista<tipo> *aux = 0;
    tipo valor;
    if(quantidadeDeElementos == 1){
        aux = inicio;
        inicio = fim = 0;
        aux->setProximo(0);
        aux->setAnterior(0);
        valor = aux->getInformacao();
        delete aux;
        quantidadeDeElementos--;
        return valor;
    }
    aux = inicio;
    inicio = aux->getProximo();
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    aux->setAnterior(0);
    aux->setProximo(0);
    valor = aux->getInformacao();
    delete aux;
    quantidadeDeElementos--;
    return valor;
}

template <class tipo>
void ListaDuplamenteEncadeadaCircular<tipo>::inserirFim(tipo elemento){
    NoLista<tipo> *pt = 0;
    try {
        pt = new NoLista<tipo>(elemento);
    } catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
    if(quantidadeDeElementos == 0){
        pt->setProximo(pt);
        pt->setAnterior(pt);
        inicio = fim = pt;
        quantidadeDeElementos++;
        return;
    }
    pt->setAnterior(fim);
    fim->setProximo(pt);
    fim = pt;
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    quantidadeDeElementos++;
    return;
}

template <class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::retirarFim(){
    if(listaVazia()) throw QString("Lista Vazia");
    NoLista<tipo> *aux = 0;
    tipo valor;
    if(quantidadeDeElementos == 1){
        aux = fim;
        inicio = fim = 0;
        aux->setProximo(0);
        aux->setAnterior(0);
        valor = aux->getInformacao();
        delete aux;
        quantidadeDeElementos--;
        return valor;
    }
    aux = fim;
    fim = aux->getAnterior();
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    aux->setAnterior(0);
    aux->setProximo(0);
    valor = aux->getInformacao();
    delete aux;
    quantidadeDeElementos--;
    return valor;
}

template <class tipo>
void ListaDuplamenteEncadeadaCircular<tipo>::inserirNoMeio(tipo elemento, int posicao){
    if((posicao > (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(posicao == 0){
        inserirInicio(elemento);
        return;
    }
    if(posicao == (quantidadeDeElementos)){
        inserirFim(elemento);
        return;
    }
    NoLista<tipo> *pt = 0;
    NoLista<tipo> *aux1 = 0;
    NoLista<tipo> *aux2 = 0;
    try{
        pt = new NoLista<tipo>(elemento);
    }catch(std::bad_alloc&){
        throw QString ("falta espaço na memória");
    }
    aux1 = inicio->getProximo();
    aux2 = inicio;
    posicao--;
    while(posicao != 0){
        aux1 = aux1->getProximo();
        posicao--;
    }
    pt->setProximo(aux1);
    aux2->setProximo(pt);
    quantidadeDeElementos++;
}
template <class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::operator[] (int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return inicio->getInformacao();}
    if(posicao == (quantidadeDeElementos - 1)){return fim->getInformacao();}
    NoLista<tipo> *aux = inicio;

    while(posicao != 0){
        aux = aux->getProximo();
        posicao--;
    }
    return aux->getInformacao();
}
template <class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::retirarDoMeio(int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return retirarInicio();}
    if(posicao == (quantidadeDeElementos - 1)){return retirarFim();}
    NoLista<tipo> *aux1 = inicio->getProximo();
    NoLista<tipo> *aux2 = inicio;
    tipo valor;
    posicao--;
    while(posicao != 0){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
        posicao--;
    }
    aux2->setProximo(aux1->getProximo());
    valor = aux1->getInformacao();
    aux1->setProximo(0);
    delete aux1;
    quantidadeDeElementos--;
    return valor;
}
template <class tipo>
void ListaDuplamenteEncadeadaCircular<tipo>::inserirOrdenado(tipo elemento){
    if(listaVazia()){
        inserirInicio(elemento);
        return;
    }
    if((fim == inicio) && (elemento < inicio->getInformacao())){
        inserirInicio(elemento);
        return;
    }else if(elemento <= inicio->getInformacao()){
        inserirInicio(elemento);
        return;
    }else if(fim == inicio){
        inserirFim(elemento);
        return;
    }
    NoLista<tipo> *pt = 0;
    NoLista<tipo> *aux1 = 0;
    NoLista<tipo> *aux2 = 0;
    try{
        pt = new NoLista<tipo>(elemento);
    }catch(std::bad_alloc&){
        throw QString ("falta espaço na memória");
    }
    aux1 = inicio->getProximo();
    aux2 = inicio;
    while((aux2->getProximo() != fim) && (elemento > aux1->getInformacao())){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
    }

    pt->setProximo(aux1);
    aux2->setProximo(pt);
    quantidadeDeElementos++;

}
template <class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::retirarElemento(tipo elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    if(elemento == inicio->getInformacao()){return retirarInicio();}
    if(elemento == fim->getInformacao()){return retirarFim();}
    NoLista<tipo> *aux1 = inicio->getProximo();
    NoLista<tipo> *aux2 = inicio;
    tipo valor;
    while((elemento != aux1->getInformacao()) && (aux1 != fim)){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
    }

    if((aux1 == fim) && (elemento != aux1->getInformacao())) throw QString ("Elemento não encontrado");

    aux2->setProximo(aux1->getProximo());
    valor = aux1->getInformacao();
    aux1->setProximo(0);
    delete aux1;
    quantidadeDeElementos--;
    return valor;
}
template <class tipo>
tipo ListaDuplamenteEncadeadaCircular<tipo>::acessarElemento(tipo elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    NoLista<tipo> *aux1 = inicio;
    while((elemento != aux1->getInformacao()) && (aux1 != fim)){
        aux1 = aux1->getProximo();
    }

    if((aux1 == fim) && (elemento != aux1->getInformacao())) throw QString ("Elemento não encontrado");

    return aux1->getInformacao();
}
template <class tipo>
ListaDuplamenteEncadeadaCircular<tipo>::~ListaDuplamenteEncadeadaCircular(){
    while(!listaVazia()){
        retirarInicio();
    }
}


}
#endif // LISTADUPLAMENTEENCADEADACIRCULAR_H

