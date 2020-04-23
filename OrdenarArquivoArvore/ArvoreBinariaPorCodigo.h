#ifndef ARVOREBINARIAPORCODIGO_H
#define ARVOREBINARIAPORCODIGO_H
#include<ArvoreBinaria.h>

namespace ED1 {
template <class tipo>
class ArvoreBinariaPorCodigo : public ArvoreBinaria<tipo>
{
private:
    bool comparador(tipo elemento, tipo elemento2);
public:
    ArvoreBinariaPorCodigo():ArvoreBinaria<tipo>(){}
};

template <class tipo>
bool ArvoreBinariaPorCodigo<tipo>::comparador(tipo elemento, tipo elemento2){
    if(elemento < elemento2)return true;
    else
        return false;
}
}
#endif // ARVOREBINARIAPORCODIGO_H
