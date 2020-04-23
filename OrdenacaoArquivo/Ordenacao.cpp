#include "Ordenacao.h"
namespace ED1 {

Ordenacao::Ordenacao()
{
}

Pilha<Aluno>* Ordenacao::ordenaPorCodigo(Pilha<Aluno>* primeiraPilha){

    ED1::Aluno aluno;

    for(int i = primeiraPilha->getQuantidadedeElementos(); i != 0; i--){
        aluno = primeiraPilha->remover();
        for(int j = i - 1; j != 0; j--){
            if(aluno.getCodigo() >= primeiraPilha->acessar().getCodigo()){
                segundaPilha.inserir(primeiraPilha->remover());
            }else{
                segundaPilha.inserir(aluno);
                aluno = primeiraPilha->remover();
            }

        }
        primeiraPilha->inserir(aluno);
        for(int k = segundaPilha.getQuantidadedeElementos(); k != 0;k--){
            primeiraPilha->inserir(segundaPilha.remover());
        }
    }
    return primeiraPilha;
}

Pilha<Aluno>* Ordenacao::ordenaPorNome(Pilha<Aluno>* primeiraPilha){

    ED1::Aluno aluno;


    for(int i = primeiraPilha->getQuantidadedeElementos(); i != 0; i--){
        aluno = primeiraPilha->remover();
        for(int j = i - 1; j != 0; j--){
            if(aluno.getNome() >= primeiraPilha->acessar().getNome()){
                segundaPilha.inserir(primeiraPilha->remover());
            }else{
                segundaPilha.inserir(aluno);
                aluno = primeiraPilha->remover();
            }

        }
        primeiraPilha->inserir(aluno);
        for(int k = segundaPilha.getQuantidadedeElementos(); k != 0;k--){
            primeiraPilha->inserir(segundaPilha.remover());
        }
    }

    return primeiraPilha;
}

}

