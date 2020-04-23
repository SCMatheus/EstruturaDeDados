#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include<No.h>
#include<string>
#include<iostream>
#include<iarvorebinaria.h>
namespace ED1{
template <class tipo>
class ArvoreBinaria : public IArvoreBinaria<tipo>
{
    //atributos
private:
    No<tipo>* raiz;

    //Metodos
private:
    void inserirRecursivo(No<tipo> **raiz, tipo elemento);
    void removerRecursivo(No<tipo> **raiz, tipo elemento);

    void emOrdemCEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const;

    void emOrdemCDireita(No<tipo>* raiz, Fila<tipo> *fila)const;

    void emOrdemPreFEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const;

    void emOrdemPreFDireita(No<tipo>* raiz, Fila<tipo> *fila)const;

    void emOrdemPosFEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const;

    void emOrdemPosFDireita(No<tipo>* raiz, Fila<tipo> *fila)const;

    tipo retornar_Maior(No<tipo> **raiz);

    virtual  bool comparador(tipo elemento, tipo elemento2) = 0;
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void inserir(tipo elemento){this->inserirRecursivo(&raiz,elemento);}
    void remover(tipo elemento){this->removerRecursivo(&raiz, elemento);}

    virtual void imprimirCEsquerda(Pilha<tipo> *pilha){emOrdemCEsquerda(raiz, pilha);}

    virtual void imprimirCDireita(Fila<tipo> *fila){emOrdemCDireita(raiz, fila);}

    virtual void imprimirPreFEsquerda(Pilha<tipo> *pilha){emOrdemPreFEsquerda(raiz, pilha);}

    virtual void imprimirPreFDireita(Fila<tipo> *fila){emOrdemPreFDireita(raiz, fila);}

    virtual void imprimirPosFEsquerda(Pilha<tipo> *pilha){emOrdemPosFEsquerda(raiz , pilha);}

    virtual void imprimirPosFDireita(Fila<tipo> *fila){emOrdemPosFDireita(raiz, fila);}

};
template <class tipo>
ArvoreBinaria<tipo>::ArvoreBinaria():
    raiz(0)
{
}
template <class tipo>
ArvoreBinaria<tipo>::~ArvoreBinaria()
{
    if(raiz != 0){
        delete raiz;
    }
}
template <class tipo>
void ArvoreBinaria<tipo>::inserirRecursivo(No<tipo> **raiz, tipo elemento){
    if(*raiz == 0){
        *raiz = new No<tipo>(elemento);
    }else
        if(comparador(elemento, (*raiz)->getDado()))
            inserirRecursivo(&(*raiz)->esquerda, elemento);
        else
            if(!comparador(elemento,(*raiz)->getDado()))
                inserirRecursivo(&(*raiz)->direita, elemento);
            else throw std::string("Elemento já Existe");
}
template <class tipo>
tipo ArvoreBinaria<tipo>::retornar_Maior(No<tipo> **raiz){
    tipo valor;
    No<tipo> *aux = 0;
    if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));
    else{
        aux = *raiz;
        valor = (*raiz)->getDado();
        *raiz = (*raiz)->esquerda;
        aux->esquerda = 0;
        aux->direita = 0;
        delete aux;
        return valor;
    }
}
template <class tipo>
void ArvoreBinaria<tipo>::removerRecursivo(No<tipo> **raiz, tipo elemento){
    No<tipo> *aux = 0;
    //std::cout<<std::endl<<"Remover Recursivo1"<<std::endl;
    if(*raiz != 0){
        //std::cout<<std::endl<<"Remover Recursivo2"<<std::endl;
        //std::cout<<"dado = "<<(*raiz)->getDado();
        if((*raiz)->getDado() == elemento){
            //std::cout<<std::endl<<"Remover Recursivo3"<<std::endl;
            aux = *raiz;
            if((*raiz)->esquerda == 0){
                *raiz = (*raiz)->direita;
                aux->esquerda = 0;
                aux->direita = 0;
                delete aux;
            }else
                if((*raiz)->direita == 0){
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;
                }else
                    {
                        (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                    }
        }else
            {
                if(comparador(((*raiz)->getDado()), elemento))
                    removerRecursivo(&(*raiz)->direita,elemento);
                else
                    if(!comparador(((*raiz)->getDado()), elemento))
                        removerRecursivo(&(*raiz)->esquerda,elemento);
        }

    }//ok
    else throw std::string("Elemento não Existe");//ok
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemCDireita(No<tipo>* raiz, Fila<tipo> *fila)const{
    if(raiz != 0){
        emOrdemCDireita(raiz->getEsquerda(), fila);
        fila->inserir(raiz->getDado());
        emOrdemCDireita(raiz->getDireita(), fila);
    }
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemPreFEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const{
    if(raiz != 0){
        pilha->inserir(raiz->getDado());
        emOrdemPreFEsquerda(raiz->getEsquerda(), pilha);
        emOrdemPreFEsquerda(raiz->getDireita(), pilha);
    }
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemPosFEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const{
    if(raiz != 0){
        emOrdemPosFEsquerda(raiz->getEsquerda(), pilha);
        emOrdemPosFEsquerda(raiz->getDireita(), pilha);
        pilha->inserir(raiz->getDado());
    }
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemPreFDireita(No<tipo>* raiz, Fila<tipo> *fila)const{
    if(raiz != 0){
        fila->inserir(raiz->getDado());
        emOrdemPreFDireita(raiz->getDireita(), fila);
        emOrdemPreFDireita(raiz->getEsquerda(), fila);
    }
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemCEsquerda(No<tipo>* raiz, Pilha<tipo> *pilha)const{
    if(raiz != 0){
        emOrdemCEsquerda(raiz->getDireita(), pilha);
        pilha->inserir(raiz->getDado());
        emOrdemCEsquerda(raiz->getEsquerda(), pilha);
    }
}

template <class tipo>
void ArvoreBinaria<tipo>::emOrdemPosFDireita(No<tipo>* raiz, Fila<tipo> *fila)const{
    if(raiz != 0){
        emOrdemPosFDireita(raiz->getDireita(), fila);
        emOrdemPosFDireita(raiz->getEsquerda(), fila);
        fila->inserir(raiz->getDado());
    }
}

}
#endif // ARVOREBINARIA_H
