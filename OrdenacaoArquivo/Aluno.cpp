#include "Aluno.h"
namespace ED1 {
Aluno::Aluno(int codigo, QString nome, QString curso, QString graduacao, QString naosei, QString data)
{
    this->codigo = codigo;
    this->nome = nome;
    this->curso = curso;
    this->graduacao = graduacao;
    this->naosei = naosei;
    this->data = data;
}
}
