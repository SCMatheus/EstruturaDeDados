#include "ListaCircular.h"

namespace ED1{

void Lista::inserirInicio(Piloto elemento){
    No *pt = 0;
    try {
        pt = new No(elemento);
    } catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
    if(listaVazia()){
        fim = inicio = pt;
        pt->setProximo(inicio);
    }else{
        pt->setProximo(inicio);
        inicio = pt;
    }
    quantidadeDeElementos++;
}

Piloto Lista::retirarInicio(){
    if(inicio==0) throw QString("Lista Vazia");
    No *pt = inicio;
    inicio = inicio->getProximo();
    Piloto valor = pt->getInformacao();
    delete pt;
    quantidadeDeElementos--;
    if(quantidadeDeElementos == 0){
        inicio = fim = 0;
    }
    return valor;
}

void Lista::inserirFim(Piloto elemento){
   No *pt = 0;
   No *aux = 0;
   try{
       pt = new No(elemento);
   }catch(std::bad_alloc&){
       throw QString ("falta espaço na memória");
   }
   if(inicio == 0){
       inicio = fim = pt;
       fim->setProximo(inicio);
   }else
   {
       aux = inicio;
       while(aux != fim){
           aux = aux->getProximo();
       }
       aux->setProximo(pt);
       fim = pt;
       fim->setProximo(inicio);
   }
    quantidadeDeElementos++;
}

Piloto Lista::retirarFim(){
    if(inicio == 0) throw QString("Lista Vazia");
    if(quantidadeDeElementos == 1){
        return retirarInicio();
    }
    No *aux1 = 0;
    No *aux2 = 0;
    Piloto valor;
    valor = fim->getInformacao();
    aux1 = inicio->getProximo();
    aux2 = inicio;
    while(aux1 != fim){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
   }
   fim = aux2;
   fim -> setProximo(inicio);
   delete aux1;
   quantidadeDeElementos--;
   return valor;
}

void Lista::inserirNoMeio(Piloto elemento, int posicao){
    if((posicao > (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(posicao == 0){
        inserirInicio(elemento);
        return;
    }
    if(posicao == (quantidadeDeElementos)){
        inserirFim(elemento);
        return;
    }
    No *pt = 0;
    No *aux1 = 0;
    No *aux2 = 0;
    try{
        pt = new No(elemento);
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
Piloto Lista::operator[] (int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return inicio->getInformacao();}
    if(posicao == (quantidadeDeElementos - 1)){return fim->getInformacao();}
    No *aux = inicio;

    while(posicao != 0){
        aux = aux->getProximo();
        posicao--;
    }
    return aux->getInformacao();
}

Piloto Lista::retirarDoMeio(int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return retirarInicio();}
    if(posicao == (quantidadeDeElementos - 1)){return retirarFim();}
    No *aux1 = inicio->getProximo();
    No *aux2 = inicio;
    Piloto valor;
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

void Lista::inserirOrdenado(Piloto elemento){
    if(listaVazia()){
        inserirInicio(elemento);
        return;
    }
    if((fim == inicio) && (elemento < inicio->getInformacao())){
        inserirInicio(elemento);
        return;
    }else if(elemento < inicio->getInformacao()){
        inserirInicio(elemento);
        return;
    }else if(fim == inicio){
        inserirFim(elemento);
        return;
    }
    No *pt = 0;
    No *aux1 = 0;
    No *aux2 = 0;
    try{
        pt = new No(elemento);
    }catch(std::bad_alloc&){
        throw QString ("falta espaço na memória");
    }
    aux1 = inicio->getProximo();
    aux2 = inicio;
    while((aux2->getProximo() != fim) && (elemento >= aux1->getInformacao())){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
    }

    pt->setProximo(aux1);
    aux2->setProximo(pt);
    quantidadeDeElementos++;

}

Piloto Lista::retirarElemento(Piloto elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    if(elemento == inicio->getInformacao()){return retirarInicio();}
    if(elemento == fim->getInformacao()){return retirarFim();}
    No *aux1 = inicio->getProximo();
    No *aux2 = inicio;
    Piloto valor;
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

Piloto Lista::acessarElemento(Piloto elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    No *aux1 = inicio;
    while((elemento != aux1->getInformacao()) && (aux1 != fim)){
        aux1 = aux1->getProximo();
    }

    if((aux1 == fim) && (elemento != aux1->getInformacao())) throw QString ("Elemento não encontrado");

    return aux1->getInformacao();
}

Lista::~Lista(){
    while(!listaVazia()){
        retirarInicio();
    }
}

}
