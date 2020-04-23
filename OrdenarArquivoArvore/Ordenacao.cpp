#include "Ordenacao.h"
namespace ED1 {

Ordenacao::Ordenacao()
{
}

Fila<Aluno>* Ordenacao::ordenaPorCodigo(Fila<Aluno>* fila){

    ED1::Aluno aluno;
    for(int i = fila->getQuantidadedeElementos(); i != 0; i--){
        aluno = fila->remover();
        for(int j = fila->getQuantidadedeElementos(); j != 0; j--){
            if(aluno.getCodigo() >= fila->acessar().getCodigo()){
                fila->inserir(fila->remover());
            }else{
                fila->inserir(aluno);
                aluno = fila->remover();
            }

        }
        fila->inserir(aluno);
    }
    return fila;
}

Fila<Aluno>* Ordenacao::ordenaPorNome(Fila<Aluno>* fila){

    ED1::Aluno aluno;
    for(int i = fila->getQuantidadedeElementos(); i != 0; i--){
        aluno = fila->remover();
        for(int j = fila->getQuantidadedeElementos(); j != 0; j--){
            if(aluno.getNome() >= fila->acessar().getNome()){
                fila->inserir(fila->remover());
            }else{
                fila->inserir(aluno);
                aluno = fila->remover();
            }

        }
        fila->inserir(aluno);
    }
    return fila;
}

}

