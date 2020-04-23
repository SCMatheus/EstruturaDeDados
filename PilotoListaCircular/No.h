#ifndef NO_H
#define NO_H
#include<Piloto.h>

namespace ED1{
class No
{
private:
    Piloto informacao;
    No *proximo;
public:
    No():proximo(0){}
    No(Piloto informacao):informacao(informacao),proximo(0){}
    ~No(){proximo=0;}
    Piloto getInformacao()const{return informacao;}
    void setInformacao(Piloto informacao){this->informacao=informacao;}
    No* getProximo()const{return proximo;}
    void setProximo(No* proximo){this->proximo = proximo;}
};
}
#endif // NO_H
