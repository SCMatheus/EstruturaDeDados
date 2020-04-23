#ifndef ARVOREBINARIAPORNOME_H
#define ARVOREBINARIAPORNOME_H
#include<ArvoreBinaria.h>

namespace ED1 {

template <class tipo>
class ArvoreBinariaPorNome : public ArvoreBinaria<tipo>
{
private:
    bool comparador(tipo elemento, tipo elemento2);
public:
    ArvoreBinariaPorNome():ArvoreBinaria<tipo>(){}
};

template <class tipo>
bool ArvoreBinariaPorNome<tipo>::comparador(tipo elemento, tipo elemento2){
    if(elemento > elemento2)return false;
    else
        return true;
}
}
#endif // ARVOREBINARIAPORNOME_H
