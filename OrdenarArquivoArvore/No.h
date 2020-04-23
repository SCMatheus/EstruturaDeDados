#ifndef NO_H
#define NO_H
#include<iostream>
namespace ED1{
template <class tipo>
class No
{
private:
    tipo dado;
public:
    No<tipo> *direita;
    No<tipo> *esquerda;
public:
    No(tipo dado);
    ~No();
    tipo getDado()const{return dado;}
    void setDado(tipo dado){this->dado = dado;}
    No<tipo>* getDireita(){return direita;}
    void setDireita(No<tipo>* direita){this->direita = direita;}
    No<tipo>* getEsquerda(){return esquerda;}
    void setEsquerda(No<tipo>* esquerda){this->esquerda = esquerda;}
};

template <class tipo>
No<tipo>::No(tipo dado):
    dado(dado),
    esquerda(0),
    direita(0)
{
}
template <class tipo>
No<tipo>::~No()
{
    if(this->esquerda != 0) delete this->esquerda;
    if(this->direita != 0)  delete this->direita;
}

}
#endif // NO_H
