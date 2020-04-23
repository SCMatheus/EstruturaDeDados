#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <ArvoreBinariaPorNome.h>
#include <ArvoreBinariaPorCodigo.h>
#include<QString>
#include <Aluno.h>
#include<fstream>
#include <Pilha.h>
#include <Fila.h>
#include <QStringList>
namespace ED1 {
class Persistencia
{
private:
    std::string linha;
    QString linhaAux;
    std::ifstream arquivo;
public:
    Persistencia(QString nomeDoArquivo);
    ~Persistencia();
    ArvoreBinariaPorCodigo<Aluno>* PegaDadosArquivo();
    ArvoreBinariaPorNome<Aluno>* PegaDadosArquivoPorNome();
    ArvoreBinariaPorNome<Aluno>* PegaDadosArquivoPorSobreNome();
};
}
#endif // PERSISTENCIA_H
