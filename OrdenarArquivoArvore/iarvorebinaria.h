#ifndef IARVOREBINARIA_H
#define IARVOREBINARIA_H
#include <FiLa.h>
#include<Pilha.h>
namespace ED1{
template <class tipo>
class IArvoreBinaria{
    virtual void inserir(tipo elemento) = 0;

    virtual void imprimirCEsquerda(Pilha<tipo> *pilha) = 0;

    virtual void imprimirCDireita(Fila<tipo> *fila) = 0;

    virtual void imprimirPreFEsquerda(Pilha<tipo> *pilha) = 0;

    virtual void imprimirPreFDireita(Fila<tipo> *fila) = 0;

    virtual void imprimirPosFEsquerda(Pilha<tipo> *pilha) = 0;

    virtual void imprimirPosFDireita(Fila<tipo> *fila) = 0;

    virtual void remover(tipo elemento) = 0;

    virtual bool comparador(tipo elemento, tipo elemento2) = 0;
};
}
#endif // IARVOREBINARIA_H
