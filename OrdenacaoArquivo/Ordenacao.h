#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <Pilha.h>
#include <Aluno.h>
namespace ED1 {
class Ordenacao
{
private:
    Pilha<Aluno> segundaPilha;
public:
    Ordenacao();
    Pilha<Aluno>* ordenaPorCodigo(Pilha<Aluno>* primeiraPilha);
    Pilha<Aluno>* ordenaPorNome(Pilha<Aluno>* primeiraPilha);
};
}
#endif // ORDENACAO_H
