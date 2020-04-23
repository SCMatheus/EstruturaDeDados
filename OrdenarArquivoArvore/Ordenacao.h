#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <Fila.h>
#include <Aluno.h>
namespace ED1 {
class Ordenacao
{
public:
    Ordenacao();
    Fila<Aluno>* ordenaPorCodigo(Fila<Aluno>* fila);
    Fila<Aluno>* ordenaPorNome(Fila<Aluno>* fila);
};
}
#endif // ORDENACAO_H
